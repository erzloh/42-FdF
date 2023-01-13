# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:57:28 by eholzer           #+#    #+#              #
#    Updated: 2023/01/13 15:49:51 by eric             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRCS_DIR 	=	sources/
SRCS_LIST	=	main.c \
				fdf_utils_1.c \
				draw_line.c \
				draw_grid.c \
				parse_map.c \
				parse_map2.c \
				handle_input.c \
				render_functions.c
SRCS		=	${addprefix ${SRCS_DIR}, ${SRCS_LIST}}

OBJS_DIR	=	objects/
OBJS_LIST	=	${SRCS_LIST:.c=.o}
OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

MLX_DIR		=	minilibx_macos
MLX			=	libmlx.a

LIB_DIR		=	libft
LIB			=	libft.a

all:			${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
				${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				make -C ${LIB_DIR}
				${CC} ${CFLAG} -o ${NAME} ${OBJS} ${LIB_DIR}/${LIB} ${MLX_DIR}/${MLX} -framework OpenGL -framework AppKit

clean:
				rm -rf ${OBJS_DIR}
				make -C ${LIB_DIR} clean

fclean:			clean
				rm -f ${NAME}
				rm -f ${LIB_DIR}/${LIB}

re:				fclean all

.PHONY:			all clean fclean re