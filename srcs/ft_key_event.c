/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:02:32 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/18 19:14:08 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	key_press(int keycode, t_mdata *dat)
{
	ft_printf("uwu [%i]\n", keycode);
	if (keycode == 53)
	{
		ft_destroyer(dat);
		// mlx_loop(dat->mlx_ptr);
	}
	return (0);
}

int	mouse_event(int keycode, t_mdata *dat)
{
	(void)dat;
	if (keycode == 4)
	{
		printf("up: [%d] zoom[%f]\n", keycode, g_zoom);
		g_zoom /= 1.2;
	}
	else if (keycode == 5)
	{
		g_zoom *= 1.2;
		printf("down: [%d] zoom[%f]\n", keycode, g_zoom);
	}
	ft_printf("keycode [%d] x[d] y[d]\n", keycode);
	return (38);
}
