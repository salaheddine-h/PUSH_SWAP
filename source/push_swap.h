/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:52 by salhali           #+#    #+#             */
/*   Updated: 2025/02/15 14:59:45 by salah            ###   ########.fr       */
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
void print_stack(t_node **stack); //function Print_stack nchofo wach Data wsslat
void push_s(t_node **list, long data); //Katzid node jdida f stack
t_node *get_last_node(t_node **stack);
t_node *new_node(long data); // Function to create a new node in the stack

// ---OP-SWAP-- //
void    swap(t_node **head);
void	swap_a(t_node **head);
void	swap_b(t_node **head);
void	swap_ab(t_node **stack_a, t_node **stack_b);
//---OP-PUSH-- //
void	push(t_node **stack_from, t_node **stack_to);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
//---OP-Rotate-- //
void	rotate_cw(t_node **head);
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	rotate_ab(t_node **stack_a, t_node **stack_b);
//---OP-Reverse-Rotate-- //
void	rotate_ccw(t_node **head);
void	r_rotate_a(t_node **head);
void	r_rotate_b(t_node **head);
void	r_rotate_ab(t_node **stack_a, t_node **stack_b);

#endif
