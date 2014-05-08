/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:54:56 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:46:26 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect		*new_vect(double x, double y, double z)
{
	t_vect	*new;

	if ((new = (t_vect *)malloc(sizeof(t_vect))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	normalize_vect(new);
	return (new);
}

double		normalize_vect(t_vect *vect)
{
	double	norme;

	norme = sqrt(pow(vect->x, 2) + pow(vect->y, 2) + pow(vect->z, 2));
	vect->x /= norme;
	vect->y /= norme;
	vect->z /= norme;
	return (norme);
}

t_vect		*cross_product(t_vect *v1, t_vect *v2)
{
	t_vect	*res;

	if ((res = new_vect(0, 0, 0)) == NULL)
		return (NULL);
	res->x = (v1->y * v2->z) - (v2->y * v1->z);
	res->y = (v1->z * v2->x) - (v2->z * v1->x);
	res->z = (v1->x * v2->y) - (v2->x * v1->y);
	normalize_vect(res);
	return (res);
}

double		find_angle(t_vect *v1, t_vect *v2)
{
	double	angle;

	angle = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
	return (angle);
}

t_vect		*get_dir_vect(t_point *upleft, t_cam *cam, int x, int y)
{
	t_vect	*dir;

	if ((dir = new_vect(0, 0, 0)) == NULL)
		return (NULL);
	dir->x = -cam->pos->x + upleft->x + cam->right->x * IND_X * x
		- cam->up->x * IND_Y * y;
	dir->y = -cam->pos->y + upleft->y + cam->right->y * IND_X * x
		- cam->up->y * IND_Y * y;
	dir->z = -cam->pos->z + upleft->z + cam->right->z * IND_X * x
		- cam->up->z * IND_Y * y;
	normalize_vect(dir);
	return (dir);
}
