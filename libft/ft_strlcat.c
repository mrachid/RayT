/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:52:01 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:57:34 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d_len;
	size_t			i;
	const char		*temp1;
	char			*temp2;

	temp1 = src;
	temp2 = dst;
	i = size;
	while (i-- != 0 && *temp2 != '\0')
		temp2++;
	d_len = temp2 - dst;
	i = size - d_len;
	if (i == 0)
		return (d_len + ft_strlen(temp1));
	while (*temp1 != '\0')
	{
		if (i != 1)
		{
			*temp2++ = *temp1;
			i--;
		}
		temp1++;
	}
	*temp2 = '\0';
	return (d_len + (temp1 - src));
}
