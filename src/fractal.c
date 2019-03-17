/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractal.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 22:32:52 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:18:12 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	compute_julia(t_fractol *frac, t_vec2 vec, double z_r, double z_i)
{
	double	c_r;
	double	c_i;
	int		i;
	double	ret;
	double	tmp;

	c_r = set_mouse_move(frac, GET_X);
	c_i = set_mouse_move(frac, GET_Y);
	i = 0;
	while ((ret = z_r * z_r + z_i * z_i) < 4 && i < frac->max_iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp * z_i + c_i;
		i++;
	}
	ret = (vec.y * WIN_WIDTH + vec.x);
	if (vec.x >= 0 && vec.y >= 0 &&
			vec.x < WIN_WIDTH && vec.y < WIN_HEIGHT && ret >= 0)
	{
		if (i < frac->max_iter && i > 0)
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = get_color(i);
		else
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = 0x1a1b1c;
	}
}

void	compute_mandelbrot(t_fractol *frac, t_vec2 vec, double c_r, double c_i)
{
	double	tmp;
	double	z_r;
	double	z_i;
	int		i;
	double	ret;

	z_r = 0.0;
	z_i = 0.0;
	i = 0;
	while ((ret = z_r * z_r + z_i * z_i) < 4 && i < frac->max_iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp * z_i + c_i;
		i++;
	}
	ret = (vec.y * WIN_WIDTH + vec.x);
	if (vec.x >= 0 && vec.y >= 0 &&
			vec.x < WIN_WIDTH && vec.y < WIN_HEIGHT && ret >= 0)
	{
		if (i < frac->max_iter && i > 0)
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = get_color(i);
		else
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = 0x1a1b1c;
	}
}

void	compute_ship(t_fractol *frac, double c_r, double c_i, t_vec2 vec)
{
	double	tmp;
	double	z_x;
	double	z_y;
	int		i;
	double	ret;

	z_x = 0;
	z_y = 0;
	i = 0;
	while ((ret = z_x * z_x + z_y * z_y) < 4 && i < frac->max_iter)
	{
		tmp = z_x * z_x - z_y * z_y + c_r;
		z_y = fabs(2.0 * z_x * z_y) + c_i;
		z_x = fabs(tmp);
		i++;
	}
	ret = (vec.y * WIN_WIDTH + vec.x);
	if (vec.x >= 0 && vec.y >= 0 &&
			vec.x < WIN_WIDTH && vec.y < WIN_HEIGHT && ret >= 0)
	{
		if (i < frac->max_iter && i > 0)
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = get_color(i);
		else
			frac->img.data[vec.y * WIN_WIDTH + vec.x] = 0x1a1b1c;
	}
}
