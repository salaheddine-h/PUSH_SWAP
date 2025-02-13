/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:54:10 by salah             #+#    #+#             */
/*   Updated: 2025/02/12 18:48:00 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stackA)
{
    t_node *first;
    t_node *second;

    if (*stackA == NULL || (*stackA)->next == NULL)
        return; // Swap impossible ila kayn moins de 2 nodes

    first = *stackA;
    second = (*stackA)->next;

    first->next = second->next; // Node 1 now points to Node 3
    second->next = first;       // Node 2 now points to Node 1
    *stackA = second;           // StackA now starts from Node 2
}

void sb(t_node **stackB)
{
    t_node *first;
    t_node *second;

    if (*stackB == NULL || (*stackB)->next == NULL)
        return; // Swap impossible ila kayn moins de 2 nodes

    first = *stackB;
    second = (*stackB)->next;

    first->next = second->next; // Node 1 now points to Node 3
    second->next = first;       // Node 2 now points to Node 1
    *stackB = second;           // StackB now starts from Node 2
}
void ss(t_node **stackA, t_node **stackB)
{
    sa(stackA); // Swap Stack A
    sb(stackB); // Swap Stack B
}
