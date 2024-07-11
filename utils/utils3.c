/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 06:34:39 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/11 04:46:48 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static long int	virgule_calculation(char *str, int i, long int *div)
{
	long int	virg;

	virg = 0;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		virg = virg * 10 + (str[i] - 48);
		*div = *div * 10;
		i++;
	}
	return (virg);
}

double	double_converter(char *str)
{
	int			signe;
	int			i;
	long int	n;
	long int	div;
	long int	virg;

	n = 0;
	i = 0;
	div = 1;
	signe = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57) && str[i] != '.')
		n = n * 10 + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	virg = virgule_calculation(str, i, &div);
	return ((n + ((double)virg / div)) * signe);
}
