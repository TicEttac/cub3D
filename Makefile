# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 11:50:47 by nisauvig          #+#    #+#              #
#    Updated: 2020/08/04 14:24:15 by nisauvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =		add.c					\
			add_redirect.c			\
			parser.c				\
			parser_next.c			\
			main.c					\
			mlx_start.c				\
			mlx_utils.c				\
			mlx_utils_2.c			\
			texture.c				\
			hooks.c					\
			hooks_utils.c			\
			ray_utils.c				\
			ray_utils_2.c			\
			sprite_utils.c			\

GNL_SRCS =	get_next_line.c			\
			get_next_line_utils.c	\

OBJS = $(addprefix srcs/, $(SRCS))
GNL_OBJS = $(addprefix gnl/, $(GNL_SRCS))

#osef des lignes de librairie, ca compile quand meme

CFLAGS = -g3 -fsanitize=address -I includes -framework OpenGL -framework AppKit -o  #-Wall -Werror -Wextra
CC = gcc
LIB = 	libft/libft.a	\
		./libmlx.a		\

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft all
	@make -C minilibX
	@mv minilibX/libmlx.a .
	@cp minilibX/mlx.h ./includes
	@${CC} ${CFLAGS} ${NAME} ${GNL_OBJS} ${OBJS} ${LIB} #&& printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"

clean:
	@rm -rf libmlx.a
	@rm -rf includes/mlx.h
	@make -C minilibX clean
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

git: fclean
	@git add .
	@git commit -m "$@"
	@git push

.PHONY: all clean fclean re
