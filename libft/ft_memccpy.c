/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:08:08 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:51:37 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		*temp;
	char		*temp2;

	temp2 = (char *)s2;
	temp = (char *)s1;
	i = 0;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (temp2[i] == (unsigned char)c)
			return (&temp[i + 1]);
		i++;
	}
	return (NULL);
}
