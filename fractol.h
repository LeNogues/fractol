/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:37:38 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 17:02:42 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

//Structure
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
	double	left_limit;
	double	right_limit;
	double	up_limit;
	double	down_limit;
	double	img_width;
	double	img_height;
	double	x;
	double	y;
	double	coord_r;
	double	coord_i;
	double	z_r;
	double	z_i;
	double	iteration;
	double	tmp;
	int		px_bits;
	int		l_byte;
	int		endian;
	int		pixel;
	int		color;
	int		zoom;
	int		scale_factor;
	int		i;
}	t_data;

///////////////////////////////////

//event.c
int		handle_keypress(int keycode, t_data *data);
int		handle_crosspress(t_data *data);
///////////////////////////////////

//init.c
int		init_ptr(t_data *data);
///////////////////////////////////

//render.c
int		render(t_data *data);
///////////////////////////////////

//clean.c
void	free_data(t_data *data);
void	free_ptr(t_data *data);
///////////////////////////////////

//init.c
int		init_variable(t_data *data);
///////////////////////////////////

//create_img.c
int		create_image(t_data *data);
///////////////////////////////////

//calcul.c
void	calcul_mandelbrot(t_data *data);
///////////////////////////////////

//color.c
void	put_color(t_data *data);
///////////////////////////////////
#endif