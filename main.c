/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:35:41 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:37:48 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

int			as_space(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void		main_2(void)
{
	char	*line;

	ft_putstr("Enter the scene file name : ");
	while (get_next_line(0, &line) != 1)
		;
	if (line && line[0])
		check_line(line);
}

void		ft_exit(char *line)
{
	char	*tmp;

	ft_putstr("Are you sure (yes/no): ");
	while (get_next_line(0, &tmp) != 1)
		;
	if (!ft_strcmp(tmp, "no") || !ft_strcmp(tmp, "n"))
	{
		free(tmp);
		main_2();
	}
	else if (!ft_strcmp(tmp, "yes") || !ft_strcmp(tmp, "y"))
	{
		free(tmp);
		free(line);
		exit(1);
	}
	else
		ft_exit(line);
}

void		check_line(char *line)
{
	int		fd;

	if (as_space(line))
	{
		ft_putendl("Wrong input, the file's name must contain only one word");
		exit(1);
	}
	else if (!ft_strcmp(line, "quit") || !ft_strcmp(line, "q"))
		ft_exit(line);
	else if ((fd = open(line, O_RDONLY)) == -1)
	{
		ft_putstr(line);
		ft_putendl(" is not a file");
		exit(0);
	}
	else
		start(fd);
	free(line);
}

int			main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	if (env)
	{
		while (!NULL)
			main_2();
	}
	return (0);
}
