/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:21:38 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 14:53:59 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	res;

	if (n < 0)
	{
		res = -1 * n;
		ft_putchar('-');
	}
	else
		res = n;
	if (res > 9)
	{
		ft_putnbr (res / 10);
		ft_putnbr (res % 10);
	}
	else
	{
		ft_putchar (res + '0');
	}
}
