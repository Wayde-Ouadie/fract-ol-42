/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:55:48 by oel-feng          #+#    #+#             */
/*   Updated: 2024/03/25 02:14:21 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	initialize_fractol(t_mlx *fractal, char **av)
{
	(void)fractal;
	ft_putendl_fd(av[1], 1);
}

int	main(int ac, char **av)
{
	t_mlx	fractal;

	if (ac == 2 && ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])))
		initialize_fractol(&fractal, av);
	else if (ac == 2 && ft_strncmp(av[1], "Tricorn", ft_strlen(av[1])))
		initialize_fractol(&fractal, av);
	else if (ac == 4 && ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		initialize_fractol(&fractal, av);
	else
	{
		ft_putendl_fd(ARG_ERR, 2);
		exit(EXIT_FAILURE);
	}
}
