/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 08:52:53 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/27 13:25:14 by jzimini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	get_decimal(char *str, int i)
{
	double		dec;
	double		div;

	dec = 0;
	++i;
	div = 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		dec = dec * 10 + (str[i] - '0');
		div *= 10;
		i++;
	}
	dec /= div;
	return (dec);
}

double			ft_atod(char *str)
{
	int			i;
	double		dec;
	double		res;
	double		neg;

	i = 0;
	res = 0;
	neg = 1;
	dec = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		dec = get_decimal(str, i);
	return ((dec + res) * neg);
}
