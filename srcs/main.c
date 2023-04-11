/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:15:58 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/12 00:52:14 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	main(void)
{
	t_mdata	dat;

	ft_mdata_init(&dat);
	mlx_key_hook(dat.win_ptr, key_press, (void *)&dat);
	mlx_hook(dat.win_ptr, XCLIENT_MESSAGE, XSTRUCTURE_NOTIFY_MASK, mlx_loop_end,
			dat.mlx_ptr);
	mlx_mouse_hook(dat.win_ptr, mouse_event, (void *)&dat);
	// mlx_loop_hook(dat.mlx_ptr);
	mlx_loop(dat.mlx_ptr);
	ft_destroyer(&dat);
	return (0);
}
