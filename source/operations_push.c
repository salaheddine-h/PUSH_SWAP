/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:58:02 by salah             #+#    #+#             */
/*   Updated: 2025/02/15 15:06:54 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // Katjib l’awal mn stack B w diro f top dyal stack A.
// // Ila stack B khawi, makaytbdl walo.
// void pa(t_node **stackA, t_node **stackB)
// {
//   t_node *top = *stackB; // Récupérer le premier élément de stackB

//     if (!stackB || !(*stackB)) // Vérifier si stackB est vide
//         return;
//     *stackB = top->next;   // Déplacer la tête de stackB au suivant
//     top->next = *stackA;   // Lier l'ancien top de B à stackA
//     *stackA = top;         // Mettre à jour la tête de stackA
// }

// void pb(t_node **stackA, t_node **stackB)
// {
//     if (!stackA || !(*stackA)) // Ila stackA khawi, matdir walo
//         return;
//     t_node *top = *stackA; // Khdi luwl élément f stackA
//     *stackA = top->next;   // Sawb stackA bach ybda mn li ba3d luwl élément
//     top->next = *stackB;   // Lieni dak luwl élément m3a stackB
//     *stackB = top;         // Dir dak élément f luwl position f stackB
// }


void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = tmp;
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}
void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}



