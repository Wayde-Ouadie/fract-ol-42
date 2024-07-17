/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:54:33 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/14 18:14:22 by oel-feng         ###   ########.fr       */
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
	char	*dst;

	dst = fractal->data.add + (y * fractal->data.line
			+ x * (fractal->data.bits / 8));
	*(unsigned int *)dst = color;
}
