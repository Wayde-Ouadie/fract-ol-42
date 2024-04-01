/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:20 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 11:51:18 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	error_msg(void)
{
	ft_putendl_fd(ARG_ERR, 2);
	exit(EXIT_FAILURE);
}

static void	initialize_fractol(t_mlx *fractal, char **av)
{
	(void)av;
	(void)fractal;
}

void	parsing(int ac, char **av, t_mlx *fractal)
{
	if (ac == 2 && (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1]))
		|| ft_strncmp(av[1], "PlaceHolder", ft_strlen(av[1]))))
		initialize_fractol(fractal, av);
	else if (ac == 4)
	{
		julia_params(fractal, av[2], av[3]);
		initialize_fractol(fractal, av);
	}
	else
		error_msg();
}
