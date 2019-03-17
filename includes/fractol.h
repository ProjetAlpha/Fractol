/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 21:26:18 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:08:46 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define INT_MAX (int) ((unsigned) -1 / 2)
# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define START_ZOOM  (WIN_WIDTH * 0.25296875)

enum	e_pressed_btn
{
	EXIT = 53,
	ZOOM_IN = 5,
	ZOOM_OUT = 4,
	STOP = 1,
	RIGHT = 124,
	LEFT = 123,
	UP = 126,
	DOWN = 125,
	INC_ITER = 69,
	DEC_ITER = 78
};

enum	e_mouse_action
{
	GET_X = 1,
	GET_Y = 2
};

enum	e_fractal_type
{
	JULIA = 1,
	MANDELBROT = 2,
	SHIP = 3
};

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct	s_vec2
{
	int y;
	int x;
}				t_vec2;

typedef struct	s_zoom
{
	double cx;
	double cy;
	double scale;
}				t_zoom;

typedef struct	s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		type;
	int		state;
	int		max_iter;
	t_vec2	mouse_move;
	t_vec2	prev_mouse_move;
	t_zoom	zoom;
}				t_fractol;

int				ft_strcmp(const char *s1, const char *s2);
void			set_mandelbrot(t_fractol *frac);
void			set_julia(t_fractol *frac);
void			set_burning_ship(t_fractol *frac);
void			compute_mandelbrot(t_fractol *frac, t_vec2 vec,
		double c_r, double c_i);
void			compute_julia(t_fractol *frac, t_vec2 vec,
		double z_r, double z_i);
void			compute_ship(t_fractol *frac, double c_r, double c_i,
		t_vec2 vec);
double			set_mouse_move(t_fractol *frac, int type);
int				get_color(int iter);
int				is_valid(char *str);
void			put_error(char *str);
int				mouse_press(int button, int x, int y, void *param);
void			set_mandelbrot(t_fractol *frac);
void			set_burning_ship(t_fractol *frac);
void			set_julia(t_fractol *frac);
int				mouse_move(int x, int y, void *param);
int				key_press(int keycode, void *param);
void			set_img(t_fractol *frac);
void			reset_img(t_fractol *frac);
t_fractol		*init_frac(void);
size_t			ft_strlen(const char *str);

#endif
