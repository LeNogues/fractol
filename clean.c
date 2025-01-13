/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:22:30 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:16 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_data(t_data *d)
{
	if (d)
	{
		free(d->buffer);
		free(d->img);
		free(d->mlx);
		free(d->win);
		free(d);
	}
}
