/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:26:13 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/15 16:05:16 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *d)
{
	printf("%f\n", d->scale_factor);
	init_variable(d);
	create_image(d);
	while (d->x < d->img_width)
	{
		d->y = 0;
		while (d->y < d->img_height)
		{
			calcul_julia(d, -0.8, 0.156);
			//calcul_mandelbrot(d);
			if (d->i != d->iteration)
				put_color(d);
			d->y++;
		}
		d->x++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (1);
}
