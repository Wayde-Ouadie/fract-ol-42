/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:08:53 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/01 04:48:14 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void mandelbrot_helper(t_mlx *fractal, int x, int y)
{
    int     i;
	t_comp	z;
	t_comp	c;
	double	tmp;
	t_rgb	rgb;

	z.x = 0;
	z.y = 0;
	i = 0;
	c.x	= (ft_scale(x, fractal->x1, fractal->x2, 800) * fractal->zoom)
		+ fractal->sh_x;
	c.y = (ft_scale(y, -2, 2, 800) * fractal->zoom)
		+ fractal->sh_y;
	while ((z.x * z.x + z.y * z.y) <= 4 && i < fractal->iter)
	{
		tmp = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	if (i == fractal->iter)
		my_mlx_put_pixel(fractal, x, y, 0x000000);
	else
		my_mlx_put_pixel(fractal, x, y, colors(&rgb, i, fractal->factor));
}

void    render_mandelbrot(t_mlx *fractal)
{
    int x;
    int y;

    x = 0;
    while (x < 800)
    {
        y = 0;
        while (y < 800)
        {
            mandelbrot_helper(fractal, x, y);
			y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->data.img, 0, 0);
}