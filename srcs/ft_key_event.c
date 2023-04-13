/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:02:32 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/13 03:31:50 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	key_press(int keycode, t_mdata *dat)
{
	ft_printf("uwu [%i]\n", keycode);
	if (keycode == XK_Escape)
		mlx_loop_end(dat->mlx_ptr);
	return (0);
}

int	mouse_event(int keycode, t_mdata *dat)
{
	(void)dat;
	if (keycode == 4)
	{
		printf("up: [%d] zoom[%f]\n", keycode, g_zoom);
		g_zoom -= 0.1;
	}
	else if (keycode == 5)
	{
		g_zoom += 0.1;
		printf("down: [%d] zoom[%f]\n", keycode, g_zoom);
	}
	return (38);
}
