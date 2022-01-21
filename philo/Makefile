NAME = philo

CFLAGS = -Wall -Werror -Wextra

SRCS = init.c main.c monitor.c philo.c utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re
