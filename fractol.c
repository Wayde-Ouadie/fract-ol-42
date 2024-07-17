/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:55:48 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/13 00:55:21 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_close(void *set)
{
	t_mlx	*fractal;

	fractal = (t_mlx *)set;
	mlx_destroy_image(fractal->mlx, fractal->data.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	rendering(char *str, t_mlx *fractal)
{
	if (ft_strncmp(str, "Mandelbrot", ft_strlen(str)))
		render_mandelbrot(fractal);
	else if (ft_strncmp(str, "Tricorn", ft_strlen(str)))
		render_tricorn(fractal);
	else if (ft_strncmp(str, "Julia", ft_strlen(str)))
		render_julia(fractal);
}

void	initialize_fractol(t_mlx *fractal, char **av)
{
	fractal->fractal = av[1];
	if (!fractal->fractal)
		return ;
	init_data(fractal);
	rendering(fractal->fractal, fractal);
	mlx_hook(fractal->win, 2, 0, ft_key, fractal);
	mlx_hook(fractal->win, 4, 0, ft_mouse, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close, fractal);
	mlx_loop(fractal->mlx);
}

int	main(int ac, char **av)
{
	t_mlx	fractal;

	parsing(ac, av, &fractal);
	exit(EXIT_SUCCESS);
}
