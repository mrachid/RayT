/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:34:40 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:52:37 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*tmp;

	if (n == 0)
		return (s1);
	tmp = malloc(n);
	if (tmp != NULL)
	{
		ft_memcpy(tmp, s2, n);
		ft_memcpy(s1, tmp, n);
		free(tmp);
	}
	return (s1);
}
