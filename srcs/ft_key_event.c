/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:02:32 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/12 00:02:51 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	key_press(int keycode, t_mdata *dat)
{
	(void)dat;
	ft_printf("uwu [%i]\n", keycode);
	if (keycode == XK_Escape)
		mlx_loop_end(dat->mlx_ptr);
	return (0);
}
