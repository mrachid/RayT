/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:56:53 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:44:50 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_point			*new_point(double x, double y, double z)
{
	t_point		*new;

	if ((new = (t_point *)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_point			*get_upleft(t_cam *cam)
{
	t_point		*upleft;

	if ((upleft = new_point(0, 0, 0)) == NULL)
		return (NULL);
	upleft->x = cam->pos->x + ((cam->dir->x * PV_DIST)
			+ (cam->up->x * (PV_HEIGHT / 2.0)))
		- (cam->right->x * (PV_WIDTH / 2.0));
	upleft->y = cam->pos->y + ((cam->dir->y * PV_DIST)
			+ (cam->up->y * (PV_HEIGHT / 2.0)))
		- (cam->right->y * (PV_WIDTH / 2.0));
	upleft->z = cam->pos->z + ((cam->dir->z * PV_DIST)
			+ (cam->up->z * (PV_HEIGHT / 2.0)))
		- (cam->right->z * (PV_WIDTH / 2.0));
	return (upleft);
}

t_point			*get_dist_pos(t_point *pos, t_vect *dir, double min)
{
	t_point		*dist;

	if ((dist = new_point(0, 0, 0)) == NULL)
		return (NULL);
	dist->x = pos->x + dir->x * min;
	dist->y = pos->y + dir->y * min;
	dist->z = pos->z + dir->z * min;
	return (dist);
}
