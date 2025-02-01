/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:52 by salhali           #+#    #+#             */
/*   Updated: 2025/02/01 21:03:28 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN    (-INT_MAX - 1)
# define INT_MAX    2147483647

#include "../libft/libft.a"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//----- Part one -------// 

int is_valid_number(char *str);
int ft_isdigit(int arg);
void print_stack(t_node **stack);
void push(t_node **stack, long data);
t_node *get_last_node(t_node **stack);


typedef struct s_node
{
    long data;
    struct s_node *next;
} t_node;

#endif