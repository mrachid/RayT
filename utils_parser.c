/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 16:39:01 by mrachid           #+#    #+#             */
/*   Updated: 2014/03/27 14:30:26 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	plane(char **tab, int i, t_item **items)
{
	int	j;
	int	k;
	int	*tp;

	k = 0;
	j = 1;
	tp = (int *)malloc(sizeof(int) * 9);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atod(tab[j]);
		j++;
		k++;
	}
	add_item(&(*items), "plane", new_plane(new_vect(tp[0], tp[1], tp[2]),
				new_point (tp[3], tp[4], tp[5])),
			new_color(tp[6], tp[7], tp[8]));
	free(tp);
	return (i);
}

int	sph(char **tab, int i, t_item **items)
{
	int	j;
	int	k;
	int	*tp;

	k = 0;
	j = 1;
	tp = (int *)malloc(sizeof(int) * 7);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atod(tab[j]);
		j++;
		k++;
	}
	add_item(&(*items), "sphere", new_sphere(tp[0], tp[1], tp[2], tp[3]),
			new_color(tp[4], tp[5], tp[6]));
	free(tp);
	return (i);
}

int	cylinder(char **tab, int i, t_item **items)
{
	int	j;
	int	k;
	int	*tp;

	k = 0;
	j = 1;
	tp = (int *)malloc(sizeof(int) * 10);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atod(tab[j]);
		j++;
		k++;
	}
	add_item(&(*items), "cylinder", new_cyl(new_point(tp[0], tp[1], tp[2]),
				new_vect(tp[3], tp[4], tp[5]), tp[6]),
			new_color(tp[7], tp[8], tp[9]));
	free(tp);
	return (i);
}

int	cone(char **tab, int i, t_item **items)
{
	int	j;
	int	k;
	int	*tp;

	k = 0;
	j = 1;
	tp = (int *)malloc(sizeof(int) * 11);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atoi(tab[j]);
		j++;
		k++;
	}
	add_item(&(*items), "cone", new_cone(new_point(tp[0], tp[1], tp[2]),
				new_vect(tp[3], tp[4], tp[5]), tp[6], tp[7]),
			new_color(tp[8], tp[9], tp[10]));
	free(tp);
	return (i);
}

int	light(char **tab, int i, t_light **light)
{
	int	j;
	int	k;
	int	*tp;

	k = 0;
	j = 1;
	tp = (int *)malloc(sizeof(int) * 6);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atod(tab[j]);
		j++;
		k++;
	}
	add_light(&(*light), "light", new_point(tp[0], tp[1], tp[2]),
			new_color(tp[3], tp[4], tp[5]));
	free(tp);
	return (i);
}
