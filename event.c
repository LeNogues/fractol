/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:03 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/15 16:47:34 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_data *d)
{
	if (keycode == 65307)
	{
		close_all(d);
		free(d->mlx);
		free(d);
		exit(0);
	}
	return (0);
}
int	handle_mouse_action(int keycode, int x, int y, t_data *d)
{
	(void)x;
	(void)y;

	if (keycode == 4)
	{
		printf("%d\n", x);
		d->mouse_x = x;
		d->mouse_y = y;
		if(d->scale_factor <= 2.25)
			d->scale_factor *= 1.02;
		else if(d->scale_factor <= 2.29)
			d->scale_factor *= 1.001;
		else if(d->scale_factor <= 2.334)
			d->scale_factor *= 1.0002;
		else if(d->scale_factor <= 2.3426)
			d->scale_factor *= 1.00002;
		else 
			d->scale_factor *= 1.000001;
		render(d);
	}
	else if (keycode == 5)
	{
		d->scale_factor *= 0.99;
		render(d);
	}
	return (0);
}

int	handle_crosspress(t_data *d)
{
	close_all(d);
	free(d->mlx);
	free(d);
	exit(0);
}
