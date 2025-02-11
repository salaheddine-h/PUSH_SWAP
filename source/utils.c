/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:50:06 by salhali           #+#    #+#             */
/*   Updated: 2025/02/10 20:52:20 by salhali          ###   ########.fr       */
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

    if (!stack)
        return NULL;
    tmp = *stack;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return(tmp);
}
// Push function to add element to the stack
void push(t_node **stack, long data)
{
    t_node *node;
    // t_node *tmp;

    node = new_node(data); 
    // tmp = get_last_node(stack);
    if (!node)
    node->next = *stack;
    *stack = node;
}

void print_stack(t_node **stack)
{
    t_node *tmp;

    if(!stack)
        return ;
    tmp = *stack;
    while (tmp)
    {
        printf("-- %ld -- \n",tmp->data);
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