NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c so_long_parsing.c utils.c so_long_back_traking.c\
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	   game_display.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBS = -lm -lX11 -lXext

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re