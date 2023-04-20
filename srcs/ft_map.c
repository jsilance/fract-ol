/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:43:14 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 13:05:32 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

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
