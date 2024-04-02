/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:08:37 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 12:42:10 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	ft_util_atof(char *str)
{
	int		i;
	double	div;
	double	res;

	i = 0;
	div = 1.0;
	res = 0.0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		div *= 0.1;
		i++;
	}
	res = res * div;
	return (res);
}

static double	ft_atof_helper(char *str, int n)
{
	double	bef_d;
	double	aft_d;
	double	result;
	char	*str1;
	char	*str2;
	
	str1 = ft_cpy(str, 0, n);
	bef_d = ft_atof_util(str1);
	str2 = ft_cpy(str, n+1, ft_strlen(str));
	aft_d = ft_util_atof(str2);
	result = bef_d + aft_d;
	free(str1);
	free(str2);
	return (result);
}

double	ft_atof(char *str)
{
	int		i;
	int		n;
	bool	check;

	n = 0;
	i = 0;
	check = true;
	while(str[i])
	{
		if (str[i] == '.')
		{
			check = false;
		}
		if (check == true)
			n++;
		i++;
	}
	return (ft_atof_helper(str, n));
}
