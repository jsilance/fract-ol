/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:43:14 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/21 17:35:31 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

double	ft_atod(char *str)
{
	double	nb;
	double	neg;
	double	div;

	nb = 0;
	neg = 1;
	div = 0.1;
	if (!str)
		return (nb);
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str && (*str == '+' || *str == '-'))
		if (*str++ == '-')
			neg = -1;
	while (*str && ft_isdigit(*str))
		nb = nb * 10 + *str++ - 48;
	if (*str && *str == '.')
		str++;
	while (*str && ft_isdigit(*str))
	{
		nb += (*str++ - 48) * div;
		div /= 10;
	}
	return (nb * neg);
}

double	ft_map(int val, int max, int newmin, int newmax)
{
	double	div;

	div = (double)max / (double)((double)newmax - (double)newmin);
	return ((double)((double)val / (double)div) + (double)newmin);
}

double	ft_fmap(double val, double max, double newmin, double newmax)
{
	double	div;

	div = (double)max / (double)((double)newmax - (double)newmin);
	return ((double)((double)val / (double)div) + (double)newmin);
}
