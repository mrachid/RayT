/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 08:52:47 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 16:46:56 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <mlx.h>

int				find_intersect(t_item *itm, t_light *li, t_vect *dir
		, t_cam *cam)
{
	double		res;
	int			i;
	t_itemfun	*f;
	t_item		*cls;
	t_item		*tmp;

	cam->min = -1;
	f = get_item_fun();
	cls = NULL;
	tmp = itm;
	while (itm)
	{
		res = 0;
		i = -1;
		while (++i < ITEMS)
			if (!ft_strcmp(itm->name, f[i].item))
				res = f[i].intsec(itm->item, cam->pos, dir);
		if (res > 0 && (res < cam->min || cam->min == -1) && (cls = itm))
			cam->min = res;
		itm = itm->next;
	}
	if (cam->min != -1)
		return (get_light(cls, tmp, li, get_dist_pos(cam->pos, dir, cam->min)));
	return (0x000000);
}

void			ft_begining(t_info *info)
{
	int			x;
	int			y;
	int			color;
	t_vect		*dir;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dir = get_dir_vect(info->scene->upleft, info->scene->cam, x, y);
			color = find_intersect(info->scene->items, info->scene->lights, dir
					, info->scene->cam);
			process_pixel(info->mlx, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img,
		0, 0);
}
