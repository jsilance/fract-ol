# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 21:01:16 by jusilanc          #+#    #+#              #
#    Updated: 2023/04/12 00:08:05 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MINILIBX = minilibx
FT_PRINTF = ft_printf

SRCS = main.c

SRC = $(addprefix srcs/, $(SRCS))

CFLAGS = -Wall -Wextra -Werror -I includes/ -I ${MINILIBX}/ -I ${FT_PRINTF}/includes/

LDFLAGS = ${FT_PRINTF}/libft.a ${MINILIBX}/libmlx_Linux.a -lm -lXext -lX11

OBJ = ${SRC:.c=.o}

${NAME}: libx ft_printf ${OBJ}
		cc ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

all: ${NAME}

%.o: %.c
		@cc ${CFLAGS} -c $< ${LDFLAGS} -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ}
		@make -C ${FT_PRINTF} clean
		@make -C ${MINILIBX} clean

fclean: clean
		@rm -rf ${NAME}
		@make -C ${FT_PRINTF} fclean

re: fclean all
		clear

libx:
		@make -C ${MINILIBX} all

ft_printf:
		@make -C ${FT_PRINTF} all

.PHONY: all re clean fclean libx ft_printf
