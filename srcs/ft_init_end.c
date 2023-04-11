/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:59:03 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/12 00:01:25 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void	ft_destroyer(t_mdata *dat)
{
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	mlx_destroy_display(dat->mlx_ptr);
}

int	ft_mdata_init(t_mdata *dat)
{
	*dat = (t_mdata){NULL, NULL, (t_vect){400, 300}};
	dat->mlx_ptr = mlx_init();
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, dat->size.x, dat->size.y,
			"title");
	return (0);
}
