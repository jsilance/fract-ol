/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:02:32 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 14:46:20 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	key_press(int keycode, t_mdata *dat)
{
	ft_printf("uwu [%i]\n", keycode);
	if (keycode == 53)
		ft_destroyer(dat);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_mdata *dat)
{
	(void)y;
	if (keycode == 4)
	{
		// printf("up: [%d] zoom[%f]\n", keycode, g_zoom);
		dat->zoom /= 1.2;
	}
	else if (keycode == 5)
	{
		dat->zoom *= 1.2;
		// printf("down: [%d] zoom[%f]\n", keycode, g_zoom);
	}
	dat->mos_x = ft_fmap(x, dat->size.x, -dat->zoom, dat->zoom) / 1;
	dat->mos_y = ft_fmap(y, dat->size.y, -dat->zoom, dat->zoom) / 1;
	printf("keycode [%d]\tx [%f]\ty [%f]\tzoom [%f]\n", keycode, dat->mos_x,
			dat->mos_y, dat->zoom);
	return (38);
}
