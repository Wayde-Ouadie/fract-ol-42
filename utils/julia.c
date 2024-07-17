/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 06:24:08 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/15 03:50:24 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	julia_helper(t_mlx *fractal, int x, int y)
{
	int		i;
	t_comp	z;
	t_comp	c;
	double	tmp;

	i = 0;
	fractal->color = 50;
	c.x = fractal->real_julia;
	c.y = fractal->imag_julia * -1;
	z.x = (ft_scale(x, fractal->x1, fractal->x2, WIDTH) * fractal->zoom)
		+ fractal->sh_x;
	z.y = -((ft_scale(y, fractal->y1, fractal->y2, HEIGHT) * fractal->zoom)
			+ fractal->sh_y);
	while ((z.x * z.x + z.y * z.y) <= 4 && i < fractal->iter)
	{
		tmp = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	if (i == fractal->iter)
		my_mlx_put_pixel(fractal, x, y, BLACK);
	else
		my_mlx_put_pixel(fractal, x, y,
			ft_scale((i * fractal->factor), BLACK, WHITE, fractal->color));
}

void	render_julia(t_mlx *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			julia_helper(fractal, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->data.img, 0, 0);
}
