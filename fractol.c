/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:36:25 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:37 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (0);
	if (argc < 2)
		d->color = 0xd79a10;
	else
		d->color = atoi(argv[1]);
	init_ptr(d);
	render(d);
	mlx_hook(d->win, 17, 0, handle_crosspress, d);
	mlx_hook(d->win, 2, 13, handle_keypress, d);
	mlx_loop(d->mlx);
	return (free_data(d), 0);
}
