/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:59:03 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/18 14:08:30 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void	ft_destroyer(t_mdata *dat)
{
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	// mlx_destroy_display(dat->mlx_ptr);
	exit(0);
}

int	ft_mdata_init(t_mdata *dat)
{
	g_zoom = 2.5;
	*dat = (t_mdata){NULL, NULL, NULL, NULL, 0, 0, 0, (t_vect){500, 500}, 2.5};
	dat->mlx_ptr = mlx_init();
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, dat->size.x, dat->size.y,
			"title");
	dat->img = mlx_new_image(dat->mlx_ptr, dat->size.x, dat->size.y);
	dat->img_addr = mlx_get_data_addr(dat->img, &dat->bpixel, &dat->size_line,
			&dat->endian);
	return (0);
}
