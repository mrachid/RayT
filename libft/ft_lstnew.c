/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 14:58:41 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:51:10 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content)
		{
			new->content_size = content_size;
			new->content = (void *)content;
			new->next = NULL;
		}
		else
		{
			new->content_size = 0;
			new->content = NULL;
		}
		return (new);
	}
	return (NULL);
}
