/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:43:14 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/15 18:43:54 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

float	ft_map(int val, int max, int newmin, int newmax)
{
	float	div;

	div = (float)max / (float)((float)newmax - (float)newmin);
	return ((float)((float)val / (float)div) + (float)newmin);
}

float	ft_fmap(float val, float max, float newmin, float newmax)
{
	float	div;

	div = (float)max / (float)((float)newmax - (float)newmin);
	return ((float)((float)val / (float)div) + (float)newmin);
}
