/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:58:32 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:58:50 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	int		i;

	i = 0;
	if (s && f)
	{
		d = ft_strnew(ft_strlen(s));
		while (s[i])
		{
			d[i] = f(i, s[i]);
			i++;
		}
		return (d);
	}
	return (NULL);
}
