/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:51:57 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:49:16 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_itemfun		*get_item_fun(void)
{
	t_itemfun	*tmp;

	tmp = (t_itemfun *)malloc(sizeof(t_itemfun) * ITEMS + 1);
	tmp[0].item = ft_strdup("sphere");
	tmp[0].norm = sphere_norm;
	tmp[0].intsec = sphere_intsec;
	tmp[0].clear = clear_sphere;
	tmp[1].item = ft_strdup("plane");
	tmp[1].norm = plane_norm;
	tmp[1].intsec = plane_intsec;
	tmp[1].clear = clear_plane;
	tmp[2].item = ft_strdup("cylinder");
	tmp[2].norm = cyl_norm;
	tmp[2].intsec = cyl_intsec;
	tmp[3].item = ft_strdup("cone");
	tmp[3].norm = cone_norm;
	tmp[3].intsec = cone_intsec;
	return (tmp);
}

t_item			*new_item(void *item, char *name, t_color *color)
{
	t_item		*new;

	if ((new = (t_item *)malloc(sizeof(t_item))) == NULL)
		return (NULL);
	new->name = name;
	new->item = item;
	new->color = color;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			add_item(t_item **itemlist, char *name, void *item,
															t_color *color)
{
	t_item		*tmp;
	t_item		*new;

	new = new_item(item, name, color);
	if (itemlist && *itemlist)
	{
		tmp = *itemlist;
		new->next = tmp;
		tmp->prev = new;
	}
	*itemlist = new;
}
