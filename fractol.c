/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:55:48 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/01 06:19:26 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	fractal;

	parsing(ac, av, &fractal);
	exit(EXIT_SUCCESS);
}

void	initialize_fractol(t_mlx *fractal, char **av)
{
	fractal->fractal = av[1];
	if (!fractal->fractal)
		return ;
	init_data(fractal);
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])))
		render_mandelbrot(fractal);
	else if (ft_strncmp(av[1], "Tricorn", ft_strlen(av[1])))
		render_tricorn(fractal);
	// else if (ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
	// 	render_julia(fractal);
	mlx_loop(fractal->mlx);
}