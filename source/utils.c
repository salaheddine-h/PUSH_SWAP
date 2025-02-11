/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:50:06 by salhali           #+#    #+#             */
/*   Updated: 2025/02/11 19:15:19 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *new_node(long data) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

t_node *get_last_node(t_node **stack)
{
    t_node *tmp;

    if (!stack | !*stack)
        return NULL;
    tmp = *stack;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return(tmp);
}
// Push function to add element to the stack
// void push(t_node **stack, long data)
// {
//     t_node *node;
//     // t_node *tmp;
//     // t_node *tmp;

//     node = new_node(data); 
//     // tmp = get_last_node(stack);
//     if (!node)
//         return;
//     node->stack =   
// }

void push(t_node **stack, long data)
{
    t_node *node = new_node(data);
    if (!node)  // ✅ Stop if memory allocation fails
        return;

    node->next = *stack;  // ✅ Insert the new node at the beginning
    *stack = node;        // ✅ Update the stack pointer
}


// void push(t_node **stack, long data)
// {
//     t_node *node;

//     node = new_node(data);
//     if (!node)
//         return;  // Stop execution if memory allocation fails

//     node->next = *stack;  // Correctly link new node to the stack
//     *stack = node;        // Update the stack pointer
// }


void print_stack(t_node **stack)
{
    t_node *tmp;

    if (!stack || !*stack)  // ✅ Check if stack exists
    {
        printf("Stack is empty or NULL\n");
        return;
    }

    tmp = *stack;
    while (tmp)  // ✅ Loop while `tmp` is not NULL
    {
        printf("-- %ld -- \n", tmp->data); // ✅ Safe to access `data`
        tmp = tmp->next;
    }
}



int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}