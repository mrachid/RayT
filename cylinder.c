/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 09:51:46 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 14:41:51 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_cyl		*new_cyl(t_point *center, t_vect *axis, double rad)
{
	t_cyl	*cyl;

	if ((cyl = (t_cyl *)malloc(sizeof(t_cyl))) == NULL)
		return (NULL);
	cyl->center = center;
	cyl->axis = axis;
	cyl->radius = rad;
	return (cyl);
}

double		cyl_intsec(void *cyl, t_point *orig, t_vect *dir)
{
	double	a;
	double	b;
	double	c;
	double	res;
	t_cyl	*tmp;

	tmp = (t_cyl *)cyl;
	a = pow(dir->x, 2) + pow(dir->z, 2);
	b = 2 * ((dir->x * (orig->x - tmp->center->x))
			+ (dir->z * (orig->z - tmp->center->z)));
	c = pow(orig->x - tmp->center->x, 2) + pow(orig->z - tmp->center->z, 2)
		- pow(tmp->radius, 2);
	res = pow(b, 2) - 4 * a * c;
	if (res < 0)
		return (-1);
	c = get_closer((-b + sqrt(res)) / (2 * a), (-b - sqrt(res)) / (2 * a));
	return (c);
}

t_vect		*cyl_norm(void *cyl, t_point *orig, t_vect *dir)
{
	t_vect	*ret;
	t_cyl	*tmp;

	(void)dir;
	tmp = (t_cyl *)cyl;
	if ((ret = new_vect(orig->x - tmp->center->x, 0,
					orig->z - tmp->center->z)) == NULL)
		return (NULL);
	return (ret);
}
