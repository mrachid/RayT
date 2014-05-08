/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:02 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:56:12 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc((ft_strlen(s1) + 1) * (sizeof(*cpy)));
	if (cpy != NULL)
		cpy = ft_strcpy(cpy, s1);
	return (cpy);
}
