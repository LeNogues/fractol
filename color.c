/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:17:59 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 17:08:45 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_gradient(int iterations, int max_iterations)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iterations / (double)max_iterations;
	red = (15 * (1 - t) * t * t * t * 255);
	green = (5 * (1 - t) * (1 - t) * t * t * 255);
	blue = (15 * (1 - t) * (1 - t) * (1 - t) * t * 100);
	return ((red << 16) | (green << 8) | (blue));
}

void	put_color(t_data *d)
{
	int	color;

	d->pixel = (d->y * d->l_byte) + (d->x * 4);
	color = color_gradient(d->i, d->iteration);
	d->buffer[d->pixel] = color;
	d->buffer[d->pixel + 1] = (color >> 8);
	d->buffer[d->pixel + 2] = (color >> 16);
}
