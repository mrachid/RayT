/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:54:00 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:55:15 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ret;

	ret = s;
	while (*ret != '\0' && *ret != (char)c)
		ret++;
	if (*ret == (char)c)
		return ((char*)ret);
	else
		return (NULL);
}
