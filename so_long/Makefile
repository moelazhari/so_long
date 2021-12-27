# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 17:20:29 by mazhari           #+#    #+#              #
#    Updated: 2021/12/27 18:55:52 by mazhari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h\
		gnl/get_next_line.h\
		libft/libft.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

BONUS_DIR = ../so_long_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
	game_start.c \
	generate_map.c \
	check_map.c \
	get_assets.c \
	render_game.c \
	move.c \
	exit_errors.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB)  $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)
	

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

bonus: 
	$(MAKE) -C  $(BONUS_DIR)
	
clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) -C  $(BONUS_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	$(MAKE) -C  $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
