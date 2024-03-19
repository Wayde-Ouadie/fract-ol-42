/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:55:48 by oel-feng          #+#    #+#             */
/*   Updated: 2024/03/17 05:43:22 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->add + (y * data->line + x * (data->bits / 8));
	*(unsigned int *)dest = color;
}

int	main(int ac, char **av)
{
	t_data	img;
	void	*mlx;
	void	*win;

	(void)av;
	(void)ac;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.add = mlx_get_data_addr(img.img, &img.bits, &img.line, &img.endian);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
