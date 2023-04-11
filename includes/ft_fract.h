/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:17:15 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/12 00:51:12 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACT_H
# define FT_FRACT_H

# include "ft_printf.h"
# include "mlx.h"
# include <math.h>

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/X.h>
# include <X11/keysymdef.h>

typedef struct s_vect
{
	int		x;
	int		y;
}			t_vect;

typedef struct s_mdata
{
	void	*mlx_ptr;
	void	*win_ptr;

	t_vect	size;
}			t_mdata;

enum		e_x_events
{
	XKEY_PRESS = 2,
	XKEY_RELEASE = 3,
	XBUTTON_PRESS = 4,
	XBUTTON_RELEASE = 5,
	XMOTION_NOTIFY = 6,
	XENTER_NOTIFY = 7,
	XLEAVE_NOTIFY = 8,
	XFOCUS_IN = 9,
	XFOCUS_OUT = 10,
	XKEYMAP_NOTIFY = 11,
	XEXPOSE = 12,
	XGRAPHICS_EXPOSE = 13,
	XNO_EXPOSE = 14,
	XVISIBILITY_NOTIFY = 15,
	XCREATE_NOTIFY = 16,
	XDESTROY_NOTIFY = 17,
	XUNMAP_NOTIFY = 18,
	XMAP_NOTIFY = 19,
	XMAP_REQUEST = 20,
	XREPARENT_NOTIFY = 21,
	XCONFIGURE_NOTIFY = 22,
	XCONFIGURE_REQUEST = 23,
	XGRAVITY_NOTIFY = 24,
	XRESIZE_REQUEST = 25,
	XCIRCULATE_NOTIFY = 26,
	XCIRCULATE_REQUEST = 27,
	XPROPERTY_NOTIFY = 28,
	XSELECTION_CLEAR = 29,
	XSELECTION_REQUEST = 30,
	XSELECTION_NOTIFY = 31,
	XCOLORMAP_NOTIFY = 32,
	XCLIENT_MESSAGE = 33,
	XMAPPING_NOTIFY = 34,
	XGENERIC_EVENT = 35,
	XLAST_EVENT = 36,
};

enum		e_x_event_masks
{
	XNO_EVENT_MASK = (0L),
	XKEY_PRESS_MASK = (1L << 0),
	XKEY_RELEASE_MASK = (1L << 1),
	XBUTTON_PRESS_MASK = (1L << 2),
	XBUTTON_RELEASE_MASK = (1L << 3),
	XENTER_WINDOW_MASK = (1L << 4),
	XLEAVE_WINDOW_MASK = (1L << 5),
	XPOINTER_MOTION_MASK = (1L << 6),
	XPOINTER_MOTION_HINT_MASK = (1L << 7),
	XBUTTON1_MOTION_MASK = (1L << 8),
	XBUTTON2_MOTION_MASK = (1L << 9),
	XBUTTON3_MOTION_MASK = (1L << 10),
	XBUTTON4_MOTION_MASK = (1L << 11),
	XBUTTON5_MOTION_MASK = (1L << 12),
	XBUTTON_MOTION_MASK = (1L << 13),
	XKEYMAP_STATE_MASK = (1L << 14),
	XEXPOSURE_MASK = (1L << 15),
	XVISIBILITY_CHANGE_MASK = (1L << 16),
	XSTRUCTURE_NOTIFY_MASK = (1L << 17),
	XRESIZE_REDIRECT_MASK = (1L << 18),
	XSUBSTRUCTURE_NOTIFY_MASK = (1L << 19),
	XSUBSTRUCTURE_REDIRECT_MASK = (1L << 20),
	XFOCUS_CHANGE_MASK = (1L << 21),
	XPROPERTY_CHANGE_MASK = (1L << 22),
	XCOLORMAP_CHANGE_MASK = (1L << 23),
	XOWNER_GRAB_BUTTON_MASK = (1L << 24),
};

void		ft_destroyer(t_mdata *dat);
int			ft_mdata_init(t_mdata *dat);
int			key_press(int keycode, t_mdata *dat);
int			mouse_event(int keycode, t_mdata *dat);

#endif