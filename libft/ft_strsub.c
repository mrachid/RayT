/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:10:59 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 15:00:39 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (s)
	{
		new = ft_strnew(len);
		if (new == NULL)
			return (NULL);
		ft_strncpy(new, &s[start], len);
		return (new);
	}
	return (NULL);
}
