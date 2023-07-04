NAME	= push_swap

src = 	./src/main.c \
		./src/push.c \
		./src/swap.c \
		./src/rotate.c \
		./src/reverse_rotate.c \
		./src/ft_stacks.c \
		./src/ft_simple_sort.c \
		./src/ft_radix.c \
		./src/ft_check.c \
		./src/utils.c

OBJS 	= $(src:.c=.o)

HEADER	= includes

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re