/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:12:36 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:52:24 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*temp;
	char		*temp2;

	temp2 = (char *)s2;
	temp = s1;
	i = 0;
	while (i < n)
	{
		*temp++ = *temp2++;
		i++;
	}
	return (s1);
}
