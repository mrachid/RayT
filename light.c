/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 09:02:11 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:39:39 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_light			*new_light(char *type, t_point *pos, t_color *color)
{
	t_light		*light;

	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		return (NULL);
	light->type = type;
	light->pos = pos;
	light->color = color;
	light->prev = NULL;
	light->next = NULL;
	return (light);
}

void			add_light(t_light **lightlist, char *type, t_point *pos
		, t_color *color)
{
	t_light		*light;
	t_light		*tmp;

	light = new_light(type, pos, color);
	if (lightlist && *lightlist)
	{
		tmp = *lightlist;
		tmp->prev = light;
		light->next = tmp;
	}
	*lightlist = light;
}

int				light_color(t_item *item, t_light *light, t_vect *vect
		, t_point *point)
{
	double		cos;
	t_vect		*norm;
	int			i;
	t_itemfun	*type;

	i = 0;
	norm = NULL;
	type = get_item_fun();
	while (i < ITEMS)
	{
		if (!ft_strcmp(item->name, type[i].item))
			norm = type[i].norm(item->item, point, vect);
		i++;
	}
	cos = find_angle(vect, norm);
	if (cos <= 0)
		return (0x000000);
	return (find_color(item->color, light->color, cos));
}
