/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:48:56 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 15:00:12 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		i++;
		j--;
	}
	return (str);
}
