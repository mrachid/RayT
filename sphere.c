/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:03:18 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:45:33 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_sphere		*new_sphere(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		return (NULL);
	sphere->center = new_point(x, y, z);
	sphere->radius = radius;
	return (sphere);
}

void			clear_sphere(void	**sphere)
{
	t_sphere	*tmp;

	tmp = (t_sphere *)*sphere;
	free(tmp->center);
	free(tmp);
	*sphere = NULL;
}

double			get_closer(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	if (t2 < t1)
		return (t2);
	if (t1 < t2)
		return (t1);
	return (t1);
}

double			sphere_intsec(void *sphere, t_point *orig, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		t;
	t_sphere	*tmp;

	tmp = (t_sphere *)sphere;
	a = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
	b = 2 * (dir->x * (orig->x - tmp->center->x) + dir->y
			* (orig->y - tmp->center->y) + dir->z
			* (orig->z - tmp->center->z));
	c = (pow(orig->x - tmp->center->x, 2)
			+ pow(orig->y - tmp->center->y, 2)
			+ pow(orig->z - tmp->center->z, 2)) - pow(tmp->radius, 2);
	t = pow(b, 2) - 4 * a * c;
	if (t < 0)
		return (-1);
	if ((t = get_closer(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a))))
		== -1)
		return (-1);
	return (t);
}

t_vect			*sphere_norm(void *sphere, t_point *orig, t_vect *dir)
{
	t_vect		*norm;
	t_sphere	*tmp;

	(void)dir;
	tmp = (t_sphere *)sphere;
	if ((norm = new_vect(orig->x - tmp->center->x, orig->y - tmp->center->y,
		orig->z - tmp->center->z)) == NULL)
		return (NULL);
	return (norm);
}
