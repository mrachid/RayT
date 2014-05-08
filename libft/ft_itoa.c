/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 09:39:02 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:49:57 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*ret;
	int				i;
	unsigned int	res;

	i = 0;
	res = (n < 0) ? (n * -1) : n;
	ret = (char *)malloc(20 * sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	while (res / 10 != 0)
	{
		ret[i] = (res % 10) + '0';
		res = (res / 10);
		i++;
	}
	if (n < 0)
	{
		ret[i + 1] = '-';
		ret[i + 2] = '\0';
	}
	if (n >= 0)
		ret[i + 1] = 0;
	ret[i] = res + '0';
	ret = ft_strrev(ret);
	return (ret);
}
