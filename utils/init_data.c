/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:02:16 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/11 04:53:03 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_data(t_mlx *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		error_msg("Initialization error.\n");
	fractal->win = mlx_new_window(fractal->mlx, 800, 800, fractal->fractal);
	if (!fractal->win)
		error_msg("Window error.\n");
	fractal->data.img = mlx_new_image(fractal->mlx, 800, 800);
	if (!fractal->data.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		error_msg("Image error.\n");
	}
	fractal->data.add = mlx_get_data_addr(fractal->data.img,
			&fractal->data.bits, &fractal->data.line, &fractal->data.endian);
	fractal->iter = 50;
	fractal->factor = 1;
	fractal->sh_x = 0;
	fractal->sh_y = 0;
	fractal->x1 = -2;
	fractal->y1 = -2;
	fractal->x2 = 2;
	fractal->y2 = 2;
	fractal->zoom = 1;
}
