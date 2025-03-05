CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -Ilibft   #-g -fsanitize=address

SRCs =  push_swap.c utils.c operations/operations_reverse_rotate.c operations/operations_push.c operations/operations_rotate.c operations/operations_swap.c check_arguments.c initialize_stack.c Sort/big_sort_utils.c Sort/optimized_big_sort.c Sort/sort_stack.c

Libft = libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(SRCs) $(Libft)
	$(CC) $(CFLAGS) $(SRCs) $(Libft) -o $(NAME)

$(Libft):
	make -s -C libft
	make bonus -s -C libft


clean:
	rm -f $(NAME)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
