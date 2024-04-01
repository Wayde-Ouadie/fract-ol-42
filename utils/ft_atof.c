/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:08:37 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 12:18:08 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static float	utils_atof(char *str)
{
	int		i;
	float	div;
	float	res;

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

static float	ft_atof_helper(char *str, int n)
{
	float	bef_d;
	float	aft_d;
	float	result;
	char	*str1;
	char	*str2;
	
	str1 = ft_cpy(str, 0, n);
	bef_d = ft_atof_util(str1);
	str2 = ft_cpy(str, n+1, ft_strlen(str));
	aft_d = utils_atof(str2);
	result = bef_d + aft_d;
	free(str1);
	free(str2);
	return (result);
}

float	ft_atof(char *str)
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
