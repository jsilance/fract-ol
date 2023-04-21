/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:15:58 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/21 17:59:39 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

static void	ft_error(int err)
{
	if (err == 1)
		ft_printf("Invalid number of arguments\n");
	else if (err == 2)
		ft_printf("Unknown argument(s) or invalid argument(s)\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mdata	dat;

	(void)argv;
	if (argc < 2)
		ft_error(1);
	ft_mdata_init(&dat);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 12))
		dat.wich_f = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 7))
	{
		dat.wich_f = 2;
		dat.j_mod_x = ft_atod(argv[2]);
		dat.j_mod_y = ft_atod(argv[3]);
	}
	else
		ft_error(1);
	mlx_key_hook(dat.win_ptr, key_press, (void *)&dat);
	mlx_mouse_hook(dat.win_ptr, mouse_event, (void *)&dat);
	mlx_loop_hook(dat.mlx_ptr, ft_put_image, (void *)&dat);
	mlx_do_key_autorepeaton(dat.mlx_ptr);
	mlx_loop(dat.mlx_ptr);
	ft_destroyer(&dat);
	return (0);
}
