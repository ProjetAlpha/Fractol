/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_fractal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 18:15:24 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:14:44 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_fractol *frac)
{
	int		i;
	int		j;
	double	z_r;
	double	z_i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			z_r = frac->zoom.cx + (i - WIN_WIDTH / 2) / frac->zoom.scale;
			z_i = frac->zoom.cy + (j - WIN_HEIGHT / 2) / frac->zoom.scale;
			compute_julia(frac, (t_vec2){.x = i, .y = j}, z_r, z_i);
			j++;
		}
		i++;
	}
}

void	set_mandelbrot(t_fractol *frac)
{
	int		i;
	int		j;
	double	c_r;
	double	c_i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			c_r = frac->zoom.cx + (i - WIN_WIDTH / 2) / frac->zoom.scale;
			c_i = frac->zoom.cy + (j - WIN_HEIGHT / 2) / frac->zoom.scale;
			compute_mandelbrot(frac, (t_vec2){.x = i, .y = j}, c_r, c_i);
			j++;
		}
		i++;
	}
}

void	set_burning_ship(t_fractol *frac)
{
	int		i;
	int		j;
	double	c_r;
	double	c_i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			c_r = frac->zoom.cx + (i - WIN_WIDTH / 2) / frac->zoom.scale;
			c_i = frac->zoom.cy + (j - WIN_HEIGHT / 2) / frac->zoom.scale;
			compute_ship(frac, c_r, c_i, (t_vec2){.x = i, .y = j});
			j++;
		}
		i++;
	}
}
