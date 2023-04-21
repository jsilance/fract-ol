/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_mj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:55:51 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/21 17:56:38 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	ft_mfractal(t_mdata *dat, int x, int y)
{
	t_mfract	v;
	int			n;

	v = (t_mfract){0, 0, 0, 0, 0, 0, 0};
	v.a = ft_fmap(x / dat->zoom, dat->size.x / dat->zoom, -dat->zoom
			+ dat->mos_x / 2.5, dat->zoom + dat->mos_x / 2.5);
	v.b = ft_fmap(y / dat->zoom, dat->size.y / dat->zoom, -dat->zoom
			+ dat->mos_y / 2.5, dat->zoom + dat->mos_y / 2.5);
	n = 0;
	v.ca = v.a;
	v.cb = v.b;
	while (n < 300)
	{
		v.aa = v.a * v.a;
		v.bb = v.b * v.b;
		v.twoab = 2 * v.a * v.b;
		v.a = v.aa - v.bb + v.ca;
		v.b = v.twoab + v.cb;
		if (fabs(v.aa * v.aa + v.bb * v.bb) > 16)
			break ;
		n++;
	}
	return (n);
}

int	ft_jfractal(t_mdata *dat, int x, int y)
{
	t_mfract	v;
	int			n;

	v = (t_mfract){0, 0, 0, 0, 0, 0, 0};
	v.a = ft_fmap(x / dat->zoom, dat->size.x / dat->zoom, -dat->zoom
			+ dat->mos_x / 2.5, dat->zoom + dat->mos_x / 2.5);
	v.b = ft_fmap(y / dat->zoom, dat->size.y / dat->zoom, -dat->zoom
			+ dat->mos_y / 2.5, dat->zoom + dat->mos_y / 2.5);
	n = 0;
	while (n < 300)
	{
		v.aa = v.a * v.a;
		v.bb = v.b * v.b;
		v.twoab = 2 * v.a * v.b;
		v.a = v.aa - v.bb + dat->j_mod_x;
		v.b = v.twoab + dat->j_mod_y;
		if (fabs(v.aa * v.aa + v.bb * v.bb) > 16)
			break ;
		n++;
	}
	return (n);
}
