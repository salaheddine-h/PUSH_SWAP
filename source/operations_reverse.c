/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:23:14 by salah             #+#    #+#             */
/*   Updated: 2025/02/15 15:07:46 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ccw(t_node **head)
{
	t_node	*prev_tail;
	t_node	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}
void	r_rotate_a(t_node **head)
{
	rotate_ccw(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_node **head)
{
	rotate_ccw(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_ccw(stack_a);
	rotate_ccw(stack_b);
	write(1, "rrr\n", 4);
}

