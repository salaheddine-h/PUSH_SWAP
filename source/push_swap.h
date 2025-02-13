/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:52 by salhali           #+#    #+#             */
/*   Updated: 2025/02/13 16:02:29 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # define INT_MIN    (-INT_MAX - 1)
// # define INT_MAX    2147483647

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

void    check_dup(t_node **stack, long num);
int is_valid_number(char *str, t_node *stack);
int ft_isdigit(int arg); //Funciton check is digite
void print_stack(t_node **stack); //function Print_stack nchofo wach Data wsslat
void push(t_node **list, long data); //Katzid node jdida f stack
t_node *get_last_node(t_node **stack);
t_node *new_node(long data); // Function to create a new node in the stack

// ---OP-SWAP-- //
void sa(t_node **stackA);
void sb(t_node **stackB);
void ss(t_node **stackA, t_node **stackB);
//---OP-PUSH-- //
void	pa(t_node **stackA, t_node **stackB);
void	pb(t_node **stackA, t_node **stackB);
//---OP-Rotate-- //
void	ra(t_node **stackA);
void	rb(t_node **stackB);
void	rr(t_node **stackA, t_node **stackB);
//---OP-Reverse-Rotate-- //
void	rrb(t_node **stackB);
void	rra(t_node **stackA);

#endif
