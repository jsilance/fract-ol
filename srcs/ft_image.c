/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:34 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/18 18:43:01 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	ft_fractal(t_mdata *dat, int x, int y)
{
	float	a;
	float	b;
	float	aa;
	float	bb;
	float	ca;
	float	cb;
	int		n;
	float	mouse_x;
	float	mouse_y;

	mouse_x = -0.7451639;
	mouse_y = 0.12655;
	a = ft_fmap(x / g_zoom, dat->size.x / g_zoom, -g_zoom + mouse_x, g_zoom
			+ mouse_x);
	b = ft_fmap(y / g_zoom, dat->size.y / g_zoom, -g_zoom + mouse_y, g_zoom
			+ mouse_y);
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
