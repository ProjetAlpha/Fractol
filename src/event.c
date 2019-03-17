/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 22:15:26 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:12:43 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	x = 0;
	y = 0;
	reset_img(frac);
	frac->zoom.cx += (double)(frac->mouse_move.x - WIN_WIDTH / 2)
		/ frac->zoom.scale;
	frac->zoom.cy += (double)(frac->mouse_move.y - WIN_HEIGHT / 2)
		/ frac->zoom.scale;
	if (button == ZOOM_IN)
	{
		frac->zoom.scale *= 2;
		set_img(frac);
	}
	if (button == ZOOM_OUT)
	{
		frac->zoom.scale /= 2;
		set_img(frac);
	}
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	reset_img(frac);
	if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
	{
		frac->mouse_move.x = x;
		frac->mouse_move.y = y;
		if (frac->type == JULIA)
			set_img(frac);
	}
	if (frac->state == 0 && frac->state != STOP)
	{
		frac->prev_mouse_move.x = x;
		frac->prev_mouse_move.y = y;
	}
	return (0);
}

int		key_press(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if ((keycode == INC_ITER || keycode == DEC_ITER)
			&& frac->max_iter < 500 && frac->max_iter >= 16)
	{
		if (keycode == INC_ITER)
			frac->max_iter += 50;
		if (keycode == DEC_ITER && frac->max_iter >= 66)
			frac->max_iter -= 50;
		set_img(frac);
	}
	if (keycode == EXIT)
	{
		mlx_destroy_image(frac->mlx_ptr, frac->img.img_ptr);
		mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
		free(frac);
		exit(0);
	}
	if (keycode == STOP && frac->state == 0)
		frac->state = STOP;
	else if (frac->state == STOP && keycode == STOP)
		frac->state = 0;
	return (0);
}
