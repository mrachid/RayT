/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 09:23:15 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 13:30:31 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color			*new_color(double r, double g, double b)
{
	t_color		*color;

	if ((color = (t_color *)malloc(sizeof(t_color))) == NULL)
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

int				color_int(t_color *color)
{
	int			ret;

	ret = 0;
	((unsigned char *)&ret)[0] = color->r;
	((unsigned char *)&ret)[1] = color->g;
	((unsigned char *)&ret)[2] = color->b;
	return (ret);
}

int				find_color(t_color *icolor, t_color *lcolor, double cos)
{
	double		r;
	double		g;
	double		b;
	int			color;

	color = 0;
	r = ((icolor->r / 255.0) * (lcolor->r / 255.0) * cos) * 255;
	g = ((icolor->g / 255.0) * (lcolor->g / 255.0) * cos) * 255;
	b = ((icolor->b / 255.0) * (lcolor->b / 255.0) * cos) * 255;
	((unsigned char *)&color)[0] = r;
	((unsigned char *)&color)[1] = g;
	((unsigned char *)&color)[2] = b;
	return (color);
}
