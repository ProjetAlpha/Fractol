/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 16:15:50 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:13:23 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*init_frac(void)
{
	t_fractol *fractol;

	if (!(fractol = malloc(sizeof(t_fractol))))
		return (NULL);
	fractol->mlx_ptr = NULL;
	fractol->win_ptr = NULL;
	fractol->img.img_ptr = NULL;
	fractol->img.data = 0;
	fractol->mouse_move.x = 0;
	fractol->mouse_move.y = 0;
	fractol->state = 0;
	fractol->max_iter = 16;
	fractol->zoom.scale = START_ZOOM;
	fractol->prev_mouse_move.x = 0;
	fractol->prev_mouse_move.y = 0;
	return (fractol);
}
