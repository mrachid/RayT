/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 11:11:54 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 14:31:08 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_cone		*new_cone(t_point *center, t_vect *axis, double rad, double angle)
{
	t_cone	*cone;

	if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		return (NULL);
	cone->center = center;
	cone->axis = axis;
	cone->radius = rad;
	cone->angle = angle;
	return (cone);
}

double		cone_intsec(void *cone, t_point *orig, t_vect *dir)
{
	double	a;
	double	b;
	double	c;
	double	res;
	t_cone	*tmp;

	tmp = (t_cone *)cone;
	a = pow(dir->x, 2) * tmp->angle + pow(dir->z, 2) * tmp->angle
		- pow(dir->y, 2);
	b = 2 * ((dir->x * (orig->x - tmp->center->x) * tmp->angle)
			+ (dir->z * (orig->z - tmp->center->z) * tmp->angle)
			- (dir->y * (orig->y - tmp->center->y)));
	c = pow(orig->x - tmp->center->x, 2) * tmp->angle
		+ pow(orig->z - tmp->center->z, 2) * tmp->angle
		- pow(orig->y - tmp->center->y, 2);
	res = pow(b, 2) - 4 * a * c;
	if (res < 0)
		return (-1);
	c = get_closer((-b + sqrt(res)) / (2 * a), (-b - sqrt(res)) / (2 * a));
	return (c);
}

t_vect		*cone_norm(void *cone, t_point *orig, t_vect *dir)
{
	t_vect	*norm;
	t_cone	*tmp;

	(void)dir;
	tmp = (t_cone *)cone;
	if ((norm = new_vect(orig->x - tmp->center->x, 0,
					orig->z - tmp->center->z)) == NULL)
		return (NULL);
	return (norm);
}
