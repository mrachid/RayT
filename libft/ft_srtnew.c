/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:26:24 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:54:56 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_store			*ft_srtnew(char *value, int val)
{
	t_store		*new;

	new = (t_store *)malloc(sizeof(t_store));
	if (new)
	{
		if (value)
		{
			new->prev = NULL;
			new->val = val;
			new->value = (void *)value;
			new->next = NULL;
		}
		else
		{
			new->val = 0;
			new->value = NULL;
		}
		return (new);
	}
	return (NULL);
}
