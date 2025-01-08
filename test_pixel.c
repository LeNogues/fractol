#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

#define MLX_ERROR 1

typedef	struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	int		color;
}	t_data;

int color_gradient(int iterations, int max_iterations)
{
    double t = (double)iterations / (double)max_iterations;
    int red;
	int green;
	int blue;


    blue= (15 * (1 - t) * t * t * t * 255);
    green = (15 * (1 - t) * (1 - t) * t * t * 255);
    red = (15 * (1 - t) * (1 - t) * (1 - t) * t * 100);

    return (red << 16) | (green << 8) | blue;
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

int	render(t_data *data)
{
	double x = 0;
	double y = 0;
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	int zoom = 300;
	int iteration_max = 60;
	double image_x = (x2 - x1) * zoom;
	double image_y = (y2 - y1) * zoom;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i;
	double tmp;
	int color;

	while(x++ < image_x )
	{
		y = 0;
		while(y++ < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while(z_r * z_r + z_i * z_i < 4 && i < iteration_max)
			{
				tmp = z_r ;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i != iteration_max)
			{
				color = color_gradient(i, iteration_max);
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			}
		}
	}    
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
    mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_hook(data->win_ptr, 17, 0, handle_crosspress, data);
	mlx_hook(data->win_ptr, 2, 13, handle_keypress, data);
    mlx_loop(data->mlx_ptr);
}

