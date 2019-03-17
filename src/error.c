/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 21:45:35 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:09:25 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		is_valid(char *str)
{
	return (ft_strcmp(str, "Julia") == 0 ||
			ft_strcmp(str, "Mandelbrot") == 0 || ft_strcmp(str, "Ship") == 0);
}

void	put_error(char *str)
{
	int len;

	len = ft_strlen(str);
	write(2, str, len);
	exit(0);
}
