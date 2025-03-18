/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:11 by salhali           #+#    #+#             */
/*   Updated: 2025/03/17 04:05:22 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*traversal;

	if (NULL == stack || NULL == stack->next)
		return (3);
	current = stack;
	while (current != NULL)
	{
		traversal = current->next;
		while (traversal != NULL)
		{
			if (current->value == traversal->value)
				return (1);
			traversal = traversal->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_stack_order(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	initialize_stack(char **argv, t_list **stack_a)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			new_node = ft_lstnew(ft_atoi(argv[i]));
			if (NULL == new_node)
				ft_error("Error, FT_ERROR initialize_stack");
			ft_lstadd_back(stack_a, new_node);
		}
		else
			initialize_stack_1(argv, i, stack_a);
		i++;
	}
	if (ft_lstsize(*stack_a) < 2)
	{
		free_stack(stack_a);
		exit (EXIT_SUCCESS);
	}
}

void	initialize_stack_1(char **argv, int index, t_list **stack_a)
{
	int		i;
	char	**args;
	t_list	*new_node;

	args = ft_split(argv[index], ' ');
	if (NULL == args)
		ft_error("Error ft_error initialize_stack_1");
	i = 0;
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		if (NULL == new_node)
			ft_error("Error initialize_stack_1");
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	ft_free(args);
}
