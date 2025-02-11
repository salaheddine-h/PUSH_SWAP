/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:52 by salhali           #+#    #+#             */
/*   Updated: 2025/02/10 21:27:35 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN    (-INT_MAX - 1)
# define INT_MAX    2147483647

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

//----- Part one -------// 
typedef struct s_node
{
    long data; // Node-->Data
    struct s_node *next;// Node-->*Next
} t_node;

int	ft_isdigit(int arg);
int is_valid_number(char *str,t_node *stack); // Check if string is a valid number
int ft_isdigit(int arg); //Funciton check is digite
void print_stack(t_node **stack); //function Print_stack nchofo wach Data wsslat
void push(t_node **stack, long data); //Katzid node jdida f stack
t_node *get_last_node(t_node **stack);
t_node *new_node(long data); // Function to create a new node in the stack

#endif
