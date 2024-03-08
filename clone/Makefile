# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 14:58:19 by hidriouc          #+#    #+#              #
#    Updated: 2024/03/06 09:49:32 by hidriouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c fractol_utils.c fractol_math.c fractol_event.c fractol_str.c

FLAGS = -Wall -Wextra -Werror -Imlx
LIBS = -lmlx -framework OpenGL -framework AppKit

OBC = $(SRC:.c=.o)

NAME = fractol

all: ${NAME}

%.o: %.c fractol.h
	cc ${FLAGS} -c $< -o $@

${NAME}: ${OBC}
	cc ${OBC} ${LIBS} -o ${NAME}

clean:
	rm -f ${OBC}

fclean: clean
	rm -f ${NAME}

re: clean all


