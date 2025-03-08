/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:50 by salhali           #+#    #+#             */
/*   Updated: 2025/03/08 21:10:51 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	rotate_stack_a(t_list **stack_a)
{
	if (rotate_stack(stack_a) == 1)
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rotate_stack_b(t_list **stack_b)
{
	if (rotate_stack(stack_b) == 1)
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rotate_both_stack(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

