NAME	= push_swap

SRCS = 	./srcs/main.c \
		./srcs/push.c \
		./srcs/swap.c \
		./srcs/rotate.c \
		./srcs/reverse_rotate.c \
		./srcs/ft_stacks.c \
		./srcs/ft_simple_sort.c \
		./srcs/ft_radix.c \
		./srcs/ft_check.c \
		./srcs/ft_exit.c \
		./srcs/ft_error.c

OBJS 	= $(SRCS:.c=.o)

HEADER	= includes

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

re_bonus:	all clean fclean re