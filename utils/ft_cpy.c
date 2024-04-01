/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:23:50 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 12:12:46 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	malloc_fail(void)
{
	ft_putendl_fd("Error in allocation", 2);
	exit(EXIT_FAILURE);
}

char	*ft_cpy(char *src, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!dest)
		malloc_fail();
	while (start < end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
