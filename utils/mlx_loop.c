/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:38:53 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/15 02:58:48 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	arrows_move(t_mlx *fractal, int key)
{
	if (key == 123)
		fractal->sh_x -= 0.025;
	else if (key == 124)
		fractal->sh_x += 0.025;
	else if (key == 125)
		fractal->sh_y += 0.025;
	else if (key == 126)
		fractal->sh_y -= 0.025;
}

static void	iter_change(t_mlx *fractal, int key)
{
	if (key == 69)
		fractal->iter += 13;
	else if (key == 78 && fractal->iter > 37)
		fractal->iter -= 13;
}

int	ft_key(int key, void *set)
{
	t_mlx	*fractal;

	fractal = (t_mlx *)set;
	if (fractal == NULL)
		return (1);
	if (key >= 123 && key <= 126)
		arrows_move(fractal, key);
	if (key == 8)
		fractal->factor += 10;
	if (key == 53)
	{
		mlx_destroy_image(fractal->mlx, fractal->data.img);
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 69 || key == 78)
		iter_change(fractal, key);
	rendering(fractal->fractal, fractal);
	return (0);
}

int	ft_mouse(int mouse, int x, int y, void *set)
{
	t_mlx	*fractal;
	double	x_line;
	double	y_line;

	fractal = (t_mlx *)set;
	if (x < 0 || y < 0)
		return (1);
	x_line = ft_scale(x, fractal->x1, fractal->x2, WIDTH);
	y_line = ft_scale(y, fractal->y1, fractal->y2, HEIGHT);
	if (mouse == 4)
		fractal->zoom *= 1.5;
	else if (mouse == 5)
		fractal->zoom *= 0.5;
	rendering(fractal->fractal, fractal);
	return (0);
}
