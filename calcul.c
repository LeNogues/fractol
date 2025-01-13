/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:36:12 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_mandelbrot(t_data *d)
{
	d->coord_r = d->x / d->zoom + d->left_limit;
	d->coord_i = d->y / d->zoom + d->up_limit;
	d->z_r = 0;
	d->z_i = 0;
	d->i = 0;
	while (d->z_r * d->z_r + d->z_i * d->z_i < 4 && d->i < d->iteration)
	{
		d->tmp = d->z_r ;
		d->z_r = d->z_r * d->z_r - d->z_i * d->z_i + d->coord_r;
		d->z_i = 2 * d->z_i * d->tmp + d->coord_i;
		d->i++;
	}
}
