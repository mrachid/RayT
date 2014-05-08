/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 11:47:26 by mrachid           #+#    #+#             */
/*   Updated: 2014/03/26 16:43:12 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void			ft_check_error(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp("light\t", tab[i], 6)
				|| !ft_strncmp("plane\t", tab[i], 6)
				|| !ft_strncmp("sphere\t", tab[i], 7)
				|| !ft_strncmp("cone\t", tab[i], 5)
				|| !ft_strncmp("cylinder\t", tab[i], 9)
				|| !ft_strncmp("cam\t", tab[i], 4))
			;
		else
		{
			ft_putendl("Error: Wrong file");
			main_2();
		}
	}
}

char			**ft_rec(int fd, char *line)
{
	t_list	*lst;
	char	**str;
	int		i;

	i = 0;
	lst = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstaddend(&lst, ft_lstnew(ft_strdup(line), i));
		i++;
		free(line);
	}
	str = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (lst)
	{
		str[i] = (char *)malloc(sizeof(char) * ft_strlen(lst->content) + 1);
		str[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	str[i] = NULL;
	ft_check_error(str);
	return (str);
}

t_scene			*ft_parser(char **str, t_scene *scn)
{
	int		i;
	char	**tab;

	i = 0;
	if ((scn = (t_scene *)malloc(sizeof(t_scene))) == NULL)
		return (NULL);
	scn->items = NULL;
	scn->lights = NULL;
	scn->cam = NULL;
	while (str[i] != NULL)
	{
		tab = ft_strsplit(str[i], '	');
		i = ft_compar(tab, i, &scn);
		i++;
	}
	if (scn->cam == NULL)
	{
		ft_putendl("Camera(cam) is missing");
		exit(0);
	}
	return (scn);
}

int				ft_compar(char **tab, int i, t_scene **scn)
{
	int			j;
	t_scene		*tmp;

	tmp = *scn;
	j = 0;
	if (!(ft_strcmp("sphere", tab[j])))
		return (i = sph(tab, i, &(tmp->items)));
	else if (!(ft_strcmp("plane", tab[j])))
		return (i = plane(tab, i, &(tmp->items)));
	else if (!(ft_strcmp("cylinder", tab[j])))
		return (i = cylinder(tab, i, &(tmp->items)));
	else if (!(ft_strcmp("cone", tab[j])))
		return (i = cone(tab, i, &(tmp->items)));
	else if (!(ft_strcmp("light", tab[j])))
		return (i = light(tab, i, &(tmp->lights)));
	else if (!(ft_strcmp("cam", tab[j])))
		return (i = cam(tab, i, &(tmp->cam)));
	return (i);
}
