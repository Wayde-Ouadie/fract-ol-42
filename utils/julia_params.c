/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:01:23 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 12:14:50 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_params(t_mlx *fractal, char *real, char *imag)
{
	//isdigit/dot wa7da;
	//atof;
	(*fractal).real_julia = ft_atof(real);
	(*fractal).imag_julia = ft_atof(imag);
	printf("real: %f && imag: %f\n", (*fractal).real_julia, (*fractal).imag_julia);
}
