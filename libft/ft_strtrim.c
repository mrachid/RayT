/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 09:29:40 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 15:00:47 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	char	*temp;
	int		i;

	i = 0;
	if (s)
	{
		while (ft_isspace(s[i]))
			i++;
		temp = ft_strrev((char *)&s[i]);
		i = 0;
		while (ft_isspace(temp[i]))
			i++;
		temp = &temp[i];
		new = ft_strnew(ft_strlen(temp));
		ft_strcpy(new, temp);
		return (ft_strrev(new));
	}
	return (NULL);
}
