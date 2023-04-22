/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:02:32 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/22 13:04:33 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	key_press(int keycode, t_mdata *dat)
{
	if (keycode == 53)
		ft_destroyer(dat);
	else if (keycode == 69)
		dat->color_shift += 1;
	else if (keycode == 78)
		dat->color_shift -= 1;
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_mdata *dat)
{
	(void)y;
	if (keycode == 4)
		dat->zoom /= 1.1;
	else if (keycode == 5)
		dat->zoom *= 1.1;
	if (keycode == 4 || keycode == 5)
	{
		dat->mos_x += ft_fmap(x, dat->size.x, -dat->zoom, dat->zoom);
		dat->mos_y += ft_fmap(y, dat->size.y, -dat->zoom, dat->zoom);
	}
	return (38);
}
