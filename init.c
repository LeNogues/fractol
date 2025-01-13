/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:16:17 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:43 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_ptr(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (free(d), -1);
	d->win = mlx_new_window(d->mlx, 800, 700, "Fractol nul");
	if (d->win == NULL)
		return (free(d->mlx), -1);
	return (1);
}

int	init_variable(t_data *d)
{
	d->x = 0;
	d->y = 0;
	d->left_limit = -2.1;
	d->right_limit = 0.6;
	d->up_limit = -1.2;
	d->down_limit = 1.2;
	d->iteration = 200;
	d->zoom = 295;
	d->img_width = (d->right_limit - d->left_limit) * d->zoom;
	d->img_height = (d->down_limit - d->up_limit) * d->zoom;
	return (0);
}
