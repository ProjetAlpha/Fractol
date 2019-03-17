/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 21:29:21 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:16:09 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *frac)
{
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "fractol 101");
	if (!frac->win_ptr)
	{
		put_error("error : mlx failed to create a window.\n");
		exit(0);
	}
	frac->img.img_ptr = mlx_new_image(frac->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	frac->img.data = (int *)mlx_get_data_addr(frac->img.img_ptr,
			&frac->img.bpp, &frac->img.size_l, &frac->img.endian);
}

void	create_fractal(t_fractol *frac)
{
	if (frac->type == JULIA)
		set_julia(frac);
	if (frac->type == MANDELBROT)
		set_mandelbrot(frac);
	if (frac->type == SHIP)
		set_burning_ship(frac);
}

void	set_mlx(t_fractol *frac)
{
	create_fractal(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr,
			frac->img.img_ptr, 0, 0);
	mlx_hook(frac->win_ptr, 2, 1L << 0, key_press, (void*)frac);
	mlx_hook(frac->win_ptr, 4, 1L << 0, mouse_press, (void*)frac);
	mlx_hook(frac->win_ptr, 6, 1L << 0, mouse_move, (void*)frac);
	mlx_loop(frac->mlx_ptr);
	if (frac->mlx_ptr && frac->img.img_ptr && frac->win_ptr)
	{
		mlx_destroy_image(frac->mlx_ptr, frac->img.img_ptr);
		mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
		free(frac);
	}
}

int		main(int ac, char **av)
{
	t_fractol *frac;

	frac = init_frac();
	if (ac == 1 || !is_valid(av[1]) || ac > 2)
		put_error(
			"Invalid argument. Usage : fractol [Julia | Mandelbrot | Sier]\n"
);
	if (ft_strcmp(av[1], "Julia") == 0)
		frac->type = JULIA;
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		frac->type = MANDELBROT;
	if (ft_strcmp(av[1], "Ship") == 0)
		frac->type = SHIP;
	init_mlx(frac);
	set_mlx(frac);
}
