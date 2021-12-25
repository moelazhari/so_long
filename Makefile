NAME = so_long

HEADER = so_long.h\
		gnl/get_next_line.h\
		libft/libft.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

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

all: $(NAME) clean

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
