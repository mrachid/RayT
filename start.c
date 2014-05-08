/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 16:40:34 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 16:45:26 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <mlx.h>

int			key_hook(int code, t_mlx *m)
{
	if (code == 65288 || code == 65535)
	{
		mlx_destroy_image(m->mlx, m->img);
		mlx_destroy_window(m->mlx, m->win);
		main_2();
	}
	if (code == 65307)
	{
		ft_putendl("thanks good luck for your project");
		exit(0);
	}
	return (0);
}

int			start(int fd)
{
	t_mlx	m;
	t_scene	*scn;
	char	**str;
	char	*line;

	line = NULL;
	scn = NULL;
	str = ft_rec(fd, line);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "raytracer");
	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);
	ft_tmp(&m, str, scn);
	mlx_key_hook(m.win, key_hook, &m);
	mlx_loop(m.mlx);
	return (1);
}
