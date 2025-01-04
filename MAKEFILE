NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c so_long_parsing.c utils.c so_long_back_traking.c\
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re