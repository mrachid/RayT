/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:22:13 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:43:56 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			inverse_plane(t_item *itemlist, t_cam *cam)
{
	t_plane	*plane;

	while (itemlist)
	{
		if (!ft_strcmp(itemlist->name, "plane"))
		{
			plane = (t_plane *)itemlist->item;
			if (find_angle(plane->vect, cam->dir) >= 0)
			{
				plane->vect->x *= -1;
				plane->vect->y *= -1;
				plane->vect->z *= -1;
			}
		}
		itemlist = itemlist->next;
	}
}

t_plane			*new_plane(t_vect *vect, t_point *center)
{
	t_plane		*plane;

	if ((plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		return (NULL);
	plane->vect = vect;
	plane->center = center;
	plane->d = -(vect->x * center->x + vect->y * center->y
		+ vect->z * center->z);
	return (plane);
}

void			clear_plane(void **plane)
{
	t_plane		*tmp;

	tmp = (t_plane *)plane;
	free(tmp->vect);
	free(tmp->center);
	*plane = NULL;
}

double			plane_intsec(void *plane, t_point *orig, t_vect *dir)
{
	double		r1;
	double		r2;
	double		r;
	t_plane		*tmp;

	tmp = (t_plane *)plane;
	r1 = tmp->vect->x * orig->x + tmp->vect->y * orig->y
		+ tmp->vect->z * orig->z + tmp->d;
	r2 = tmp->vect->x * dir->x + tmp->vect->y * dir->y + tmp->vect->z * dir->z;
	r = -(r1 / r2);
	return (r);
}

t_vect			*plane_norm(void *plane, t_point *orig, t_vect *dir)
{
	t_plane		*tmp;

	tmp = (t_plane *)plane;
	(void)orig;
	(void)dir;
	return (tmp->vect);
}
