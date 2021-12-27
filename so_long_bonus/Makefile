# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 17:20:29 by mazhari           #+#    #+#              #
#    Updated: 2021/12/27 17:49:58 by mazhari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

HEADER = so_long_bonus.h\
		gnl/get_next_line.h\
		libft/libft.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main_bonus.c \
	game_start_bonus.c \
	generate_map_bonus.c \
	check_map_bonus.c \
	get_assets_bonus.c \
	render_game_bonus.c \
	move_bonus.c \
	exit_errors_bonus.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT_LIB) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re bonus
