/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:26:24 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:54:49 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_srtaddend(t_store **alst, t_store *elem)
{
	t_store		*temp;

	if (elem)
	{
		if (alst && *alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			elem->prev = temp;
			temp->next = elem;
		}
		else
			*alst = elem;
	}
}
