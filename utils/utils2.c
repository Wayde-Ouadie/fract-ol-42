/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 06:34:39 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/17 23:07:35 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	check_args_helper(char *str, int flag)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1)
	{
		if (str[0] == '+' || str[0] == '-')
		{
			if (flag == 1)
				error_msg(REAL_ERR);
			else if (flag == 2)
				error_msg(IMAG_ERR);
		}
	}
	else if (len == 2)
	{
		if ((str[0] == '+' || str[0] == '-') && str[1] == '.')
		{
			if (flag == 1)
				error_msg(REAL_ERR);
			else if (flag == 2)
				error_msg(IMAG_ERR);
		}
	}
}

static void	check_args(char *str, int flag)
{
	int	i;
	int	len;
	int	virg;

	i = -1;
	virg = 0;
	len = ft_strlen(str);
	check_args_helper(str, flag);
	while (str[++i] && virg <= 1)
	{
		if (i == 0 && (str[0] == '+' || str[0] == '-'))
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			if (str[i] == '.')
				virg++;
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
			break ;
	}
	if (i != len || virg > 1 || len == 0)
	{
		if (flag == 1)
			error_msg(REAL_ERR);
		else if (flag == 2)
			error_msg(IMAG_ERR);
	}
}

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

double	double_converter(char *str, int flag)
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
	check_args(str, flag);
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
