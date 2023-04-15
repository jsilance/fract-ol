/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxl_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:19:07 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/15 18:26:18 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void	ft_pixels_set(t_mdata *dat, int x, int y, int color)
{
	char	*dst;

	dst = dat->img_addr + (y * dat->size_line + x * (dat->bpixel / 8));
	*(unsigned int *)dst = color;
}
