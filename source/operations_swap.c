/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:47:18 by salah             #+#    #+#             */
/*   Updated: 2025/02/15 15:06:11 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // sa (swap a): Swap the first 2 elements at the top of stack a.
// // Do nothing if there is only one or no elements.

// // Ex :  Katbdl blasa dyal 2 l’awal f stack A. Ila kayn ghir wahed ola khawi, ma kaytbdl walo.

// void sa(t_node **stackA)
// {
//     t_node *first;
//     t_node *second;

//     if (*stackA == NULL || (*stackA)->next == NULL)
//         return; // Swap impossible ila kayn moins de 2 nodes

//     first = *stackA;
//     second = (*stackA)->next;

//     first->next = second->next; // Node 1 now points to Node 3
//     second->next = first;       // Node 2 now points to Node 1
//     *stackA = second;           // StackA now starts from Node 2
// }

// // sb (swap b): Swap the first 2 elements at the top of stack b.
// // Do nothing if there is only one or no elements

// //Ex :  Nafschi haja b7al sa, walakin f stack B.

// void sb(t_node **stackB)
// {
//     t_node *first;
//     t_node *second;

//     if (*stackB == NULL || (*stackB)->next == NULL)
//         return; // Swap impossible ila kayn moins de 2 nodes

//     first = *stackB;
//     second = (*stackB)->next;

//     first->next = second->next; // Node 1 now points to Node 3
//     second->next = first;       // Node 2 now points to Node 1
//     *stackB = second;           // StackB now starts from Node 2
// }

// // ss : sa and sb at the same time.

// //Ex :  Katdir sa o sb f nafs waqt.

// void ss(t_node **stackA, t_node **stackB)
// {
//     sa(stackA); // Swap Stack A
//     sb(stackB); // Swap Stack B
// }


void	swap(t_node **head)
{
	t_node	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}
void	swap_a(t_node **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}