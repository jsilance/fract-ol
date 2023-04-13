/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:34 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/13 04:11:31 by jusilanc         ###   ########.fr       */
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

	a = ft_map(x, dat->size.x, -g_zoom, g_zoom);
	b = ft_map(y, dat->size.y, -g_zoom, g_zoom);
	n = 0;
	ca = a;
	cb = b;
	while (n < 100)
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

	// int		pixel_bits;
	// int		line_bytes;
	// int		endian;
	// char	*buf;
	// buf = mlx_get_data_addr(dat->img, &pixel_bits, &line_bytes, &endian);
	x = 0;
	mlx_clear_window(dat->mlx_ptr, dat->win_ptr);
	while (x < dat->size.x)
	{
		y = 0;
		while (y < dat->size.y)
		{
			n = ft_fractal(dat, x, y);
			bright = ft_map(n, 100, 0, 255);
			if (n == 100)
				bright = 0;
			color = bright << 16 | bright << 8 | bright;
			// buf[x + y * dat->size.y + 0] = (color >> 24);
			// buf[x + y * dat->size.y + 1] = (color >> 16) & 0xFF;
			// buf[x + y * dat->size.y + 2] = (color >> 8) & 0xFF;
			// buf[x + y * dat->size.y + 3] = (color)&0xFF;
			mlx_pixel_put(dat->mlx_ptr, dat->win_ptr, x, y, color);
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	return (0);
}
