/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:26:24 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:54:36 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_srtadd(t_store **alst, t_store *elem)
{
	if (elem)
	{
		if (alst && *alst)
		{
			(*alst)->prev = elem;
			elem->next = *alst;
		}
		*alst = elem;
	}
}
