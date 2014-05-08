/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:40:07 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 15:00:21 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbstr(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}

static char		*ft_pieceset(const char *s, char c)
{
	char	*p;
	size_t	i;
	size_t	len;

	p = NULL;
	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	p = ft_strnew(len);
	while (s[i] != c && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc((ft_nbstr(s, c) + 1) * sizeof(*tab));
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			tab[j] = ft_pieceset(&s[i], c);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
