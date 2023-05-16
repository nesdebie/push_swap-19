SRC = 	./src/main.c \
		./src/push.c \
		./src/swap.c \
		./src/rotate.c \
		./src/reverse_rotate.c \
		./src/ft_stacks.c \
		./src/ft_simple_sort.c \
		./src/ft_radix.c \
		./src/ft_check.c \
		./src/ft_exit.c \
		./libft/ft_split.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_atoi.c \
		./libft/ft_isdigit.c

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./includes/push_swap.h

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re