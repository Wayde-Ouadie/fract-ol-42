# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 05:23:31 by oel-feng          #+#    #+#              #
#    Updated: 2024/07/11 02:55:12 by oel-feng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c utils/parsing.c utils/mandelbrot.c utils/tricorn.c utils/julia.c utils/init_data.c \
	utils/utils1.c utils/utils2.c utils/utils3.c utils/mlx_loop.c
	
OBJ = ${SRC:.c=.o}
NAME = fractol
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
all: ${NAME}

%.o:%.c fractol.h
	@${CC} ${FLAG} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@${CC} ${FLAG} ${MLX} $^ -o $(NAME)

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all


re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = -2 * z.re * z.im + c->im;
		z.re = re_temp;