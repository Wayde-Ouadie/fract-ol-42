/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:20 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/15 03:20:02 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	julia_params(t_mlx *fractal, char *real, char *imag)
{
	fractal->real_julia = double_converter(real, 1);
	fractal->imag_julia = double_converter(imag, 2);
}

void	parsing(int ac, char **av, t_mlx *fractal)
{
	if (ac == 2 && (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1]))
			|| ft_strncmp(av[1], "Tricorn", ft_strlen(av[1]))))
		initialize_fractol(fractal, av);
	else if (ac == 4 && ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
	{
		julia_params(fractal, av[2], av[3]);
		initialize_fractol(fractal, av);
	}
	else
		error_msg(ARG_ERR);
}
