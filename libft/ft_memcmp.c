/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:16:12 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:52:17 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	int			res;

	i = 0;
	while (i < n)
	{
		res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
