/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_big_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:27 by salhali           #+#    #+#             */
/*   Updated: 2025/03/20 08:46:33 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_big_sort(t_list **stack_a, t_list **stack_b)
{
	if (reverse_sorted_percentage(*stack_a) >= 70)
	{
		while (*stack_a)
		{
			push_stack_b(stack_a, stack_b);
		}
		push_back_to_stack_a(stack_a, stack_b);
	}
	else
	{
		big_sort(stack_a, stack_b);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	stack_size;
	int	range;

	stack_size = ft_lstsize(*stack_a);
	tab = sorted_stack_in_tab(stack_a, stack_size);
	if (stack_size <= 100)
		range = 17;
	else
		range = 30;
	push_elements_to_stack_b(stack_a, stack_b, tab, range);
	push_back_to_stack_a(stack_a, stack_b);
	free(tab);
}



void	push_elements_to_stack_b(t_list **stack_a, t_list **stack_b, int *tab,
		int range)
{
	int	stack_size;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[i])
		{
			push_stack_b(stack_a, stack_b);
			rotate_stack_b(stack_b);
			i++;
		}
		else if (range + i < stack_size && (*stack_a)->value <= tab[range + i])
		{
			push_stack_b(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->value <= (*stack_b)->next->value)
				swap_stack_b(stack_b);
			i++;
		}
		else
			rotate_stack_a(stack_a);
	}
}

void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	max_elmnt_pos;

	while (*stack_b)
	{
		max_elmnt_pos = max_element_postion(*stack_b);
		if (max_elmnt_pos <= (ft_lstsize(*stack_b) / 2))
		{
			while (max_elmnt_pos > 0)
			{
				rotate_stack_b(stack_b);
				max_elmnt_pos--;
			}
		}
		else
		{
			max_elmnt_pos = ft_lstsize(*stack_b) - max_elmnt_pos;
			while (max_elmnt_pos > 0)
			{
				reverse_rotate_stack_b(stack_b);
				max_elmnt_pos--;
			}
		}
		push_stack_a(stack_a, stack_b);
	}
		// 🔴 Correction : Dir reverse `stack_a` bach ywali trié mn sghir l kbiiiir.
	stack_size = ft_lstsize(*stack_a);
	while (stack_size > 0)
	{
			reverse_rotate_stack_a(stack_a);
			stack_size--;
	}
}

int	reverse_sorted_percentage(t_list *stack)
{
	int		count;
	int		total;
	t_list	*temp;

	count = 0;
	total = ft_lstsize(stack);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			count++;
		temp = temp->next;
	}
	return ((count * 100) / total);
}
