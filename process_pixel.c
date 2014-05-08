/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:48:09 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:45:00 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <mlx.h>

void			process_pixel(t_mlx *mlx, int x, int y, int color)
{
	int			i;
	long int	place;
	long int	end;

	i = 0;
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sl),
			&(mlx->endian));
	place = x * (mlx->bpp / 8) + y * mlx->sl;
	end = WIDTH * (mlx->bpp / 8) + HEIGHT * mlx->sl;
	while ((i < mlx->bpp / 8) && place < end && place > 0)
	{
		mlx->data[place + i] = ((char *)&color)[i];
		i++;
	}
}
