# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 05:23:31 by oel-feng          #+#    #+#              #
#    Updated: 2024/04/01 11:48:53 by oel-feng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c utils/utils1.c utils/parsing.c utils/julia_params.c utils/ft_atof_util.c \
	utils/ft_atof.c utils/ft_cpy.c \

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