# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:57:28 by eholzer           #+#    #+#              #
#    Updated: 2022/12/24 21:31:48 by eric             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	main.c \
			fdf_utils_1.c \
			draw_line.c \
			draw_grid.c \
			parse_map.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g

MLX_DIR	=	minilibx_macos
MLX		=	libmlx.a

# MLX_DIR	=	minilibx_mms
# MLX		=	libmlx.dylib

LIB_DIR =	libft
LIB		=	libft.a

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIB_DIR}
			${CC} ${CFLAG} -o ${NAME} ${OBJS} ${LIB_DIR}/${LIB} ${MLX_DIR}/${MLX} -framework OpenGL -framework AppKit

clean:
			rm -f ${OBJS}
			make -C ${LIB_DIR} clean

fclean:		clean
			rm -f ${NAME}
			rm -f ${LIB_DIR}/${LIB}

re:			fclean all

.PHONY:		all clean fclean re