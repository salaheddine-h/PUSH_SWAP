/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:57 by salhali           #+#    #+#             */
/*   Updated: 2025/03/18 03:18:11 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **dest_stack, t_list **src_stack)
{
	t_list	*tmp;
	t_list	*dest_head;
	t_list	*src_head;

	if (ft_lstsize(*src_stack) == 0)
		return (0);
	dest_head = *dest_stack;
	src_head = *src_stack;
	tmp = src_head;
	src_head = src_head->next;
	*src_stack = src_head;
	if (!dest_head)
	{
		dest_head = tmp;
		dest_head->next = NULL;
		*dest_stack = dest_head;
	}
	else
	{
		tmp->next = dest_head;
		*dest_stack = tmp;
	}
	return (0);
}

int	push_stack_a(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 1)
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	push_stack_b(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == 1)
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}

