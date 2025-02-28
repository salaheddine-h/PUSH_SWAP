# Define compiler
CC = cc

# Define CFLAGS (compiler flags)
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft   #-g -fsanitize=address

# Source code files
SRCs =  push_swap.c utils.c operations/operations_reverse_rotate.c operations/operations_push.c operations/operations_rotate.c operations/operations_swap.c check_arguments.c initialize_stack.c sort/big_sort_utils.c sort/optimized_big_sort.c sort/sort_stack.c
Libft = libft/libft.a

# Executable name
NAME = push_swap

# Main target (to build the executable)
all: $(NAME)

# How to build the executable
$(NAME): $(SRCs) $(Libft)
	$(CC) $(CFLAGS) $(SRCs) $(Libft) -o $(NAME)

$(Libft):
	make -s -C libft
	make bonus -s -C libft

# Target to clean up object files
clean:
	rm -f $(NAME)
	make clean -C libft

# Target to clean up object files & the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

# Rebuild everything (clean first, then build)
re: fclean all
