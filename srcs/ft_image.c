/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:34 by jusilanc          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:53 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

static int	ft_hsv_shifter(int n, int shift)
{
	n += shift;
	if (n > 359)
		return (n - 360);
	if (n < 0)
		return (n + 360);
	return (n);
}

int	ft_iter_to_hsv(int n, int max_iter, int shift)
{
	int	new_n;
	int	color;

	new_n = ft_hsv_shifter(ft_map(n, max_iter, 0, 359), shift);
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

static int	ft_fract_selector(t_mdata *dat, t_vect v)
{
	if (dat->wich_f == 1)
		return (ft_mfractal(dat, v.x, v.y));
	if (dat->wich_f == 2)
		return (ft_jfractal(dat, v.x, v.y));
	return (0);
}

int	ft_put_image(t_mdata *dat)
{
	t_vect	size;
	int		color;
	int		n;
	int		bright;

	size = (t_vect){0, 0};
	mlx_clear_window(dat->mlx_ptr, dat->win_ptr);
	while (size.x < dat->size.x)
	{
		size.y = 0;
		while (size.y < dat->size.y)
		{
			n = ft_fract_selector(dat, size);
			bright = ft_map(n, 300, 0, 255);
			if (n == 300)
				bright = 0;
			color = ft_iter_to_hsv(n, 1000, dat->color_shift) * bright;
			ft_pixels_set(dat, size.x, size.y, color);
			size.y++;
		}
		size.x++;
	}
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	return (0);
}
