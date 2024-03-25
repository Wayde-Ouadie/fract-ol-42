/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:56:12 by oel-feng          #+#    #+#             */
/*   Updated: 2024/03/25 02:14:09 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define ARG_ERR "Wrong arguments provided :\n\
||./fractol Mandelbrot  ||\n\
||./fractol Julia z i   ||\n||./fractol Tricorn     ||" 

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bits;
	int		line;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

//utils
size_t	ft_strlen(char *str);
void	ft_putendl_fd(char *s, int fd);
bool	ft_strncmp(char *s1, char *s2, size_t n);

#endif