/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 08:34:38 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 13:39:21 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <mlx.h>

int				expose_hook(t_info *info)
{
	ft_begining(info);
	return (0);
}

int				cam(char **tab, int i, t_cam **cam)
{
	int			j;
	int			k;
	int			*tp;

	k = 0;
	j = 1;
	(*cam) = (t_cam *)malloc(sizeof(t_cam));
	tp = (int *)malloc(sizeof(int) * 9);
	while (tab[j] != '\0')
	{
		tp[k] = ft_atod(tab[j]);
		j++;
		k++;
	}
	(*cam)->pos = new_point(tp[0], tp[1], tp[2]);
	(*cam)->dir = new_vect(tp[3], tp[4], tp[5]);
	(*cam)->up = new_vect(tp[6], tp[7], tp[8]);
	(*cam)->right = cross_product((*cam)->up, (*cam)->dir);
	free(tp);
	return (i);
}

void			ft_tmp2(t_mlx *m, t_scene *sc)
{
	t_info		*info;

	if ((info = (t_info *)malloc(sizeof(t_info))) == NULL)
		return ;
	info->mlx = m;
	info->scene = sc;
	info->scene->name = ft_strdup("exemple");
	mlx_expose_hook(m->win, expose_hook, info);
	ft_begining(info);
}

void			ft_tmp(t_mlx *mlx, char **str, t_scene *scene)
{
	scene = ft_parser(str, scene);
	scene->upleft = get_upleft(scene->cam);
	ft_tmp2(mlx, scene);
}
