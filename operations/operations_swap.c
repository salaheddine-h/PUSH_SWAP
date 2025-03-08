/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:45 by salhali           #+#    #+#             */
/*   Updated: 2025/03/08 21:10:47 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	return (0);
}

int	swap_stack_a(t_list **stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	swap_stack_b(t_list **stack_b)
{
	if (swap(stack_b) == 1)
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	swap_both_stack(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

