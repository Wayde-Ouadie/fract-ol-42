/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:11:24 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/01 04:57:45 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	error_msg(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	my_mlx_put_pixel(t_mlx *fractal, int x, int y, int color)
{
	char	*dest;

	dest = fractal->data.add + (y * fractal->data.line 
			+ x * (fractal->data.bits / 8));
	*(unsigned int*)dest = color;
}

static int	colors_helper(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	colors(t_rgb *rgb, int iter, int factor)
{
	rgb->red = (iter * factor) % 255;
	rgb->green = (iter * (factor + 13)) % 255;
	rgb->blue = (iter * (factor + 37)) % 255;
	return (colors_helper(rgb->red, rgb->green, rgb->blue));
}
