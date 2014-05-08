/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 10:01:06 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:37:55 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static double	get_light_dist(t_light *li, t_point *pos)
{
	double		dist;

	dist = sqrt(pow(li->pos->x - pos->x, 2) + pow(li->pos->y - pos->y, 2)
				+ pow(li->pos->z - pos->z, 2));
	return (dist);
}

static t_vect	*get_light_vect(t_light *li, t_point *pos)
{
	t_vect		*light;

	light = new_vect(li->pos->x - pos->x, li->pos->y - pos->y,
			li->pos->z - pos->z);
	return (light);
}

static t_vect	*gere_light(t_item *cls, t_item *itm, t_light *li, t_point *pos)
{
	int			i;
	double		dist;
	t_vect		*light;
	t_itemfun	*fun;

	fun = get_item_fun();
	light = get_light_vect(li, pos);
	dist = get_light_dist(li, pos);
	while (itm)
	{
		i = 0;
		while (itm != cls && i < ITEMS)
		{
			if (!ft_strcmp(fun[i].item, itm->name)
					&& fun[i].intsec(itm->item, pos, light) > 0
					&& fun[i].intsec(itm->item, pos, light) < dist)
				return (NULL);
			i++;
		}
		itm = itm->next;
	}
	free(fun);
	return (light);
}

int				get_light(t_item *cls, t_item *itm, t_light *li, t_point *pos)
{
	t_color		*final;
	t_vect		*light;
	int			color;

	final = new_color(0, 0, 0);
	light = NULL;
	while (li)
	{
		if ((light = gere_light(cls, itm, li, pos)) != NULL)
		{
			color = light_color(cls, li, light, pos);
			final->r += ((unsigned char *)&color)[0];
			final->g += ((unsigned char *)&color)[1];
			final->b += ((unsigned char *)&color)[2];
			free(light);
		}
		li = li->next;
	}
	final->r = (final->r > 255) ? 255 : final->r;
	final->g = (final->g > 255) ? 255 : final->g;
	final->b = (final->b > 255) ? 255 : final->b;
	return (color_int(final));
}
