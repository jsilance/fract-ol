# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 21:01:16 by jusilanc          #+#    #+#              #
#    Updated: 2023/04/18 19:09:31 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MINILIBX = minilibx
FT_PRINTF = ft_printf

SRCS = main.c ft_key_event.c ft_init_end.c ft_image.c ft_map.c ft_pxl_set.c

SRC = $(addprefix srcs/, $(SRCS))

CFLAGS = -Wall -Wextra -Werror -I includes/ -I ${MINILIBX}/ -I ${FT_PRINTF}/includes/ -Imlx

LDFLAGS = ${FT_PRINTF}/libft.a -lmlx -Lmlx -framework OpenGL -framework AppKit

OBJ = ${SRC:.c=.o}

${NAME}: libx ft_printf ${OBJ}
		cc ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

all: ${NAME}

%.o: %.c
		@cc ${CFLAGS} -c $< -o ${<:.c=.o}

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

test: all
		./${NAME}

.PHONY: all re clean fclean libx ft_printf test
