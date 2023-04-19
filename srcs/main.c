/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:15:58 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/19 15:40:17 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int	main(void)
{
	t_mdata	dat;

	ft_mdata_init(&dat);
	mlx_key_hook(dat.win_ptr, key_press, (void *)&dat);
	mlx_hook(dat.win_ptr, XCLIENT_MESSAGE, XSTRUCTURE_NOTIFY_MASK, mlx_loop,
			dat.mlx_ptr);
	mlx_mouse_hook(dat.win_ptr, mouse_event, (void *)&dat);
	// mlx_mouse_get_pos(dat.win_ptr, &dat.mos_x, &dat.mos_y);
	// mlx_loop_hook(dat.mlx_ptr);
	// test
	mlx_loop_hook(dat.mlx_ptr, ft_put_image, (void *)&dat);
	// ft_put_image(&dat);
	mlx_loop(dat.mlx_ptr);
	ft_destroyer(&dat);
	return (0);
}
