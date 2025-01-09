#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

#define MLX_ERROR 1

typedef	struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    void    *img_ptr;
	int		color;
	double multiple;
	double x;
	double y;
	double x1;
	double x2;
	double y1;
	double y2;
	int zoom;
	int iteration_max;
	double image_x;
	double image_y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i;
	double tmp;
    int pixel_bits;
    int line_bits;
    int endian;
    char *buffer;
    int pixel;
}	t_data;

int color_gradient(int iterations, int max_iterations)
{
    double t = (double)iterations / (double)max_iterations;
    int red;
	int green;
	int blue;

    red = (15 * (1 - t) * t * t * t * 255);
    green = (5 * (1 - t) * (1 - t) * t * t * 255);
    blue  = (15 * (1 - t) * (1 - t) * (1 - t) * t * 100);

    return (red << 16) | (green << 8) | (blue);
}

int	render(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->x1 = -2.1 + data->multiple;
	data->x2 = 0.6 - data->multiple;
	data->y1 = -1.2 + data->multiple;
	data->y2 = 1.2 - data->multiple;
	data->iteration_max = 305;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;

	data->img_ptr = mlx_new_image(data->mlx_ptr, 800, 700);
 	if (!data->img_ptr)
        return (MLX_ERROR);
	data->buffer = mlx_get_data_addr(data->img_ptr, &data->pixel_bits, &data->line_bits, &data->endian);
	while(data->x < data->image_x )
	{
		data->y = 0;
		while(data->y < data->image_y)
		{
			data->c_r = data->x / data->zoom + data->x1;
			data->c_i = data->y / data->zoom + data->y1;
			data->z_r = 0;
			data->z_i = 0;
			data->i = 0;
			while(data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->i < data->iteration_max)
			{
				data->tmp = data->z_r ;
				data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
				data->z_i = 2 * data->z_i * data->tmp + data->c_i;
				data->i++;
			}
			if (data->i != data->iteration_max)
			{
                data->pixel = (data->y * data->line_bits) + (data->x * 4);
                int color = color_gradient(data->i, data->iteration_max);
				data->buffer[data->pixel] = color;
				data->buffer[data->pixel + 1] = (color >> 8);
				data->buffer[data->pixel + 2] = (color >> 16);
            }
			data->y++;
		}
		data->x++;
	}    
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        free(data);
		exit(0);
    }
	if (keycode == 112)
    {
		data->multiple+=0.1;
		data->zoom*=1.15;
    	render(data);
    }
	if (keycode == 65453)
    {
		data->multiple-=0.1;
		data->zoom*=0.85;
    	render(data);
    }
    return (0);
}

int	handle_crosspress(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    free(data);
	exit(0);
    return (0);
}

int	main(int argc, char **argv)
{
    t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc < 2)
		data->color = 0xd79a10;
	else
		data->color = atoi(argv[1]);
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        return (free(data), MLX_ERROR);
    data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 700,"my window");
    if (data->win_ptr == NULL)
		return (free(data->win_ptr), MLX_ERROR);
    data->zoom = 295;
    render(data);
	mlx_hook(data->win_ptr, 17, 0, handle_crosspress, data);
	mlx_hook(data->win_ptr, 2, 13, handle_keypress, data);
    mlx_loop(data->mlx_ptr);
}