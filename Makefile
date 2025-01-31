# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salhali <salhali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:01:58 by salhali           #+#    #+#              #
#    Updated: 2025/01/30 15:12:14 by salhali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

RM = rm -rf 

CFLAGS = -Wall -Wextra -Werror 

CC = cc 

SCRS = push_swap.c libft/libft.a ft_printf/ft_printf.c 

all : $(NAME)
	