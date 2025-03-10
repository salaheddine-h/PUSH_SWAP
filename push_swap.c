/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:09:29 by salhali           #+#    #+#             */
/*   Updated: 2025/03/10 03:32:00 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2 && check_stack_order(stack_a) == 1)
		swap_stack_a(stack_a);
	else if (size == 3)
		sort_3_number(stack_a);
	else if (size == 4)
		sort_4_number(stack_a, stack_b);
	else if (size == 5)
		sort_5_number(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (check_arguments(argv) == 0)// if return 1 donc free all stackA and stackB
		{
			initialize_stack(argv, &stack_a);
			if (check_duplicates(stack_a) == 1)
				free_stack_and_exit(&stack_a, "Error", 1);
			if (check_stack_order(&stack_a) == 0)
				free_stack_and_exit(&stack_a, "NULL", 0);
			if (ft_lstsize(stack_a) <= 5)
				small_sort(&stack_a, &stack_b);
			if (ft_lstsize(stack_a) > 5)
				optimized_big_sort(&stack_a, &stack_b);
		}
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
//      99      08      63    543
// argv[0] argv[1] argv[2] argv[3]  
// args = "99   01  21"   "9000"  "NULL";

// "99   01  21"   "900"


// stacka = "99" "01" "21" "900"