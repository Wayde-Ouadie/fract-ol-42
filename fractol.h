/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:56:12 by oel-feng          #+#    #+#             */
/*   Updated: 2024/04/01 11:51:33 by oel-feng         ###   ########.fr       */
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
./fractol Mandelbrot\n./fractol Julia z i\n./fractol PlaceHolder" 
# define REAL_ERR "Please provide a correct real number"
# define IMAG_ERR "Please provide a correct imaginary number"

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
	float	real_julia;
	float	imag_julia;
}	t_mlx;

//utils
size_t	ft_strlen(char *str);
float	ft_atof_util(char *str);
void	ft_putendl_fd(char *s, int fd);
char	*ft_cpy(char *src, int start, int end);

//parsing
float	ft_atof(char *str);
bool	ft_strncmp(char *s1, char *s2, size_t n);
void	parsing(int ac, char **av, t_mlx *fractal);
void	julia_params(t_mlx *fractal, char *real, char *imag);

#endif