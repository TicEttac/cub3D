# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 11:50:47 by nisauvig          #+#    #+#              #
#    Updated: 2020/06/06 19:13:18 by nisauvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =		add.c					\
			add_redirect.c			\
			parser.c				\
			parser_next.c			\
			main.c					\
			mlx_start.c				\

GNL_SRCS =	get_next_line.c			\
			get_next_line_utils.c	\

OBJS = $(addprefix srcs/, $(SRCS))
GNL_OBJS = $(addprefix gnl/, $(GNL_SRCS))

#osef des lignes de librairie, ca compile quand meme

CFLAGS = -I includes -I /usr/X11/include/ -g3 -fsanitize=address -L /usr/X11/lib/ -l mlx -framework OpenGL -framework AppKit -o#-o -Wall -Werror -Wextra
CC = gcc
LIB = 	libft/libft.a

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft all
	@${CC} ${CFLAGS} ${NAME} ${GNL_OBJS} ${OBJS} ${LIB} #&& printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"

clean:
	@make -C libft clean

fclean:
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

git: fclean
	@git add .
	@git commit -m "$@"
	@git push

.PHONY: all clean fclean re
