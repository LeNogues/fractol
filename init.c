/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:16:17 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/15 16:00:00 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (free(d), -1);
	d->win = mlx_new_window(d->mlx, 1000, 800, "Fractol beau");
	if (d->win == NULL)
		return (free(d->mlx), -1);
	d->scale_factor = 1;
	d->mouse_x = 0;
	d->mouse_y = 0;
	
	return (1);
}

int	init_variable(t_data *d)
{
	double zoom_by_width;
	double zoom_by_height;
	
	d->x = 0;
	d->left_limit = -3.1 + d->scale_factor + (350 * 0.0001);
	d->right_limit = 1.6 - d->scale_factor;
	d->up_limit = -2.2 + d->scale_factor + (350 * 0.0001);
	d->down_limit = 2.2 - d->scale_factor;
	d->iteration = 70;
	zoom_by_width = 800 / (d->right_limit - d->left_limit);
	zoom_by_height = 700 / (d->down_limit - d->up_limit);
	if(zoom_by_height < zoom_by_height)
		d->zoom = zoom_by_height;
	else
		d->zoom = zoom_by_width;
	d->img_width = 1000/*(d->right_limit - d->left_limit) * d->zoom*/;
	d->img_height = 900/*(d->down_limit - d->up_limit) * d->zoom*/;
	return (0);
}
