/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:09:39 by salhali           #+#    #+#             */
/*   Updated: 2025/03/08 21:09:41 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_SUCCESS);
}

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*head;

	if (NULL == stack || NULL == *stack)
		return ;
	head = *stack;
	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
	*stack = NULL;
}

void	free_stack_and_exit(t_list **stack, char *msg, int true)
{
	free_stack(stack);
	if (true)
		ft_error(msg);
}
