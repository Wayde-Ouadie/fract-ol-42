/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:56:12 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/11 04:39:53 by oel-feng         ###   ########.fr       */
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
./fractol Mandelbrot\n./fractol Julia z i\n./fractol Tricorn\n" 
# define REAL_ERR "Please provide a correct real number.\n"
# define IMAG_ERR "Please provide a correct imaginary number.\n"
# define BLACK 0x000000
# define WHITE 0XFFFFFF

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
	char	*fractal;
	void	*win;
	void	*mlx;
	t_data	data;
	int	    factor;
	int		iter;
	double	sh_x;
	double	sh_y;
	double	zoom;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	real_julia;
	double	imag_julia;
}	t_mlx;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;


void	error_msg(char *s);
size_t	ft_strlen(char *str);
void	init_data(t_mlx *fractal);
int		ft_key(int key, void *set);
double	double_converter(char *str);
void	render_julia(t_mlx *fractal);
void	ft_putendl_fd(char *s, int fd);
void	render_tricorn(t_mlx *fractal);
void	render_mandelbrot(t_mlx *fractal);
void	rendering(char *str, t_mlx *fractal);
bool	ft_strncmp(char *s1, char *s2, size_t n);
void	parsing(int ac, char **av, t_mlx *fractal);
int		ft_mouse(int mouse, int x, int y, void *set);
void	initialize_fractol(t_mlx *fractal, char **av);
double	ft_scale(double x, double max, double nmin, double nmax);
void	my_mlx_put_pixel(t_mlx *fractal, int x, int y, int color);

#endif