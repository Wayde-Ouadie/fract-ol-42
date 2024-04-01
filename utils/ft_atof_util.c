/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:14:29 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 11:39:59 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	ft_sign(char c)
{
	if (c == 45)
		return (-1);
	return (1);
}

float	ft_atof_util(char *str)
{
	int		i;
	int		sign;
	float	res;

	i = 0;
	sign = 1;
	res = 0.0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == 43 || str[i] == 45)
		sign = ft_sign(str[i++]);
	while (str[i])
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}