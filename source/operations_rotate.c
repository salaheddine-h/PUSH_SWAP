/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:43:16 by salah             #+#    #+#             */
/*   Updated: 2025/02/15 15:08:47 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_cw(t_node **head)
{
	t_node	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}
void	rotate_a(t_node **head)
{
	rotate_cw(head);
	write (1, "ra\n", 3);
}

void	rotate_b(t_node **head)
{
	rotate_cw(head);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_cw(stack_a);
	rotate_cw(stack_b);
	write(1, "rr\n", 3);
}