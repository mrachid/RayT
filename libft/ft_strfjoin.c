/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:36:02 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:56:30 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char const *s2)
{
	int		s_len;
	int		d_len;
	char	*temp;

	if (s1 && s2)
	{
		s_len = ft_strlen(s1);
		d_len = ft_strlen(s2);
		temp = ft_strnew (s_len + d_len + 1);
		if (temp == NULL)
			return (NULL);
		ft_strcpy(temp, s1);
		ft_strcat(temp, s2);
		free(s1);
		return (temp);
	}
	return (NULL);
}
