/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 22:22:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:11:24 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	set_img(t_fractol *frac)
{
	frac->img.data = (int *)mlx_get_data_addr(frac->img.img_ptr,
			&frac->img.bpp, &frac->img.size_l,
			&frac->img.endian);
	if (frac->type == MANDELBROT)
		set_mandelbrot(frac);
	if (frac->type == JULIA)
		set_julia(frac);
	if (frac->type == SHIP)
		set_burning_ship(frac);
	mlx_put_image_to_window(frac->mlx_ptr,
			frac->win_ptr, frac->img.img_ptr, 0, 0);
}

void	reset_img(t_fractol *frac)
{
	mlx_destroy_image(frac->mlx_ptr, frac->img.img_ptr);
	frac->img.img_ptr = mlx_new_image(frac->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	frac->img.bpp = 0;
	frac->img.size_l = 0;
	frac->img.size_l = 0;
}

double	set_mouse_move(t_fractol *frac, int type)
{
	if (type == GET_X)
	{
		if (frac->mouse_move.x == 0)
			return (0.285);
		else if (frac->state == STOP && frac->prev_mouse_move.x != 0)
			return ((double)frac->prev_mouse_move.x / 1000.0);
		else
			return ((double)frac->mouse_move.x / 1000.0);
	}
	if (type == GET_Y)
	{
		if (frac->mouse_move.y == 0)
			return (0.01);
		else if (frac->state == STOP && frac->prev_mouse_move.y != 0)
			return ((double)frac->prev_mouse_move.y / 100000.0);
		else
			return ((double)frac->mouse_move.y / 100000.0);
	}
	return (0.0);
}

int		get_color(int iter)
{
	int			i;
	static int	colors[] = {0x421e0f, 0x19071A, 0x09012F, 0x040449, 0x000764,
		0x0C2C8A, 0x1852B1, 0x397DD1, 0x86B5E5,
		0xD3ECF8, 0xF1E9BF, 0xF8C95F, 0xFFAA00,
		0xCC8000, 0x995700, 0x6A3403, 0xA2D680};

	i = iter % 16;
	return (colors[i]);
}
