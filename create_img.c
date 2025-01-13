/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:15:39 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 17:00:51 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_image(t_data *d)
{
	d->img = mlx_new_image(d->mlx, 800, 700);
	if (!d->img)
		return (-1);
	d->buffer = mlx_get_data_addr(d->img, &d->px_bits, &d->l_byte, &d->endian);
	return (1);
}
