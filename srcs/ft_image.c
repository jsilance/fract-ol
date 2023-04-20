/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:34 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 14:35:23 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	ft_fractal(t_mdata *dat, int x, int y)
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	ca;
	double	cb;
	int		n;

	a = ft_fmap(x / dat->zoom, dat->size.x / dat->zoom, -dat->zoom + dat->mos_x,
			dat->zoom + dat->mos_x);
	b = ft_fmap(y / dat->zoom, dat->size.y / dat->zoom, -dat->zoom + dat->mos_y,
			dat->zoom + dat->mos_y);
	n = 0;
	ca = a;
	cb = b;
	while (n < 300)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (fabs(a + b) > 16)
			break ;
		n++;
	}
	return (n);
}
int	ft_iter_to_hsv(int n, int max_iter)
{
	int	new_n;
	int	color;

	new_n = ft_map(n, max_iter, 0, 359);
	color = (255 << 16) + (255 << 8) + (255);
	if (n > 240)
		color = ((int)ft_map(new_n - 240, 119, 0, 255)) + ((int)ft_map(new_n
					- 240, 119, 255, 0) << 8);
	else if (n > 120 && n < 240)
		color = ((int)ft_map(new_n - 120, 119, 255, 0) << 16)
			+ ((int)ft_map(new_n - 120, 119, 0, 255) << 8);
	else
		color = ((int)ft_map(new_n, 119, 255, 0)) + ((int)ft_map(new_n, 119, 0,
					255) << 16);
	return (color);
}

int	ft_put_image(t_mdata *dat)
{
	int	x;
	int	y;
	int	color;
	int	n;
	int	bright;

	x = 0;
	mlx_clear_window(dat->mlx_ptr, dat->win_ptr);
	while (x < dat->size.x)
	{
		y = 0;
		while (y < dat->size.y)
		{
			n = ft_fractal(dat, x, y);
			bright = ft_map(n, 300, 0, 255);
			if (n == 300)
				bright = 0;
			// color = bright << 16 | bright << 8 | bright;
			color = ft_iter_to_hsv(n, 300) * bright;
			// if (n == 500)
			// 	color = 0;
			ft_pixels_set(dat, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	return (0);
}
