/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:39:53 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/01 02:54:14 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

bool	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((s1[a] || s2[a]) && a < n)
	{
		if (s1[a] != s2[a])
			return (false);
		a++;
	}
	return (true);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	if (!s)
		return ;
	a = 0;
	while (s[a])
		ft_putchar_fd(s[a++], fd);
	ft_putchar_fd('\n', fd);
}

double ft_scale(double x, double max
		, double nmin, double nmax)
{
    double range;
    double y;
    
    range = nmax - nmin;
    y = max + nmin;
    return (range * x / y);
}
