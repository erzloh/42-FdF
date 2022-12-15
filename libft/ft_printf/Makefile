# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:17:57 by eholzer           #+#    #+#              #
#    Updated: 2022/12/14 10:10:05 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			d_specifier.c \
			u_specifier.c \
			p_specifier.c \
			x_specifier.c \
			other_specifiers.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			cp libft/libft.a .
			mv libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re