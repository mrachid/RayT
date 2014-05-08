/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:13:34 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:59:59 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		if (!s2[j])
		{
			i = i - (j - 1);
			return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
