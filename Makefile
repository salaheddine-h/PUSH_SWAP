# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salhali <salhali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:01:58 by salhali           #+#    #+#              #
#    Updated: 2025/02/02 16:55:01 by salhali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

RM = rm -rf 

CFLAGS = -Wall -Wextra -Werror 

CC = cc 

SCRS = push_swap.c libft/libft.a 

OBJ = $(SCRS:.c=.o)

all : $(NAME)

$(NAME) :
		make all -C libft
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		
clean :
	make clean -C libft
	$(RM) $(NAME)

fclean : clean 
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all 
