/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:34 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/15 19:34:10 by jusilanc         ###   ########.fr       */
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
	while (n < 400)
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

int	ft_put_image(t_mdata *dat)
{
	int	x;
	int	y;
	int	bright;
	int	color;
	int	n;

	x = 0;
	mlx_clear_window(dat->mlx_ptr, dat->win_ptr);
	while (x < dat->size.x)
	{
		y = 0;
		while (y < dat->size.y)
		{
			n = ft_fractal(dat, x, y);
			bright = ft_map(n, 400, 0, 255);
			if (n == 400)
				bright = 0;
			color = bright << 16 | bright << 8 | bright;
			ft_pixels_set(dat, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	return (0);
}
