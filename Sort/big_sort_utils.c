#include "push_swap.h"

int	*sorted_stack_in_tab(t_list **stack_a, int stack_size)
{
	int		*tab;
	t_list	*head;
	int		i;

	tab = malloc(sizeof(int) * stack_size);
	if (!tab)
		ft_error("Error");
	head = *stack_a;
	i = 0;
	while (head)
	{
		tab[i] = head->value;
		head = head->next;
		i++;
	}
	tab = bubble_sort(tab, stack_size);
	return (tab);
}

int	max_element_postion(t_list *stack_a)
{
	int		current_max_value;
	int		max_postion;
	int		i;
	t_list	*head;

	i = 0;
	head = stack_a;
	current_max_value = head->value;
	while (head)
	{
		if (head->value > current_max_value)
		{
			current_max_value = head->value;
			max_postion = i;
		}
		head = head->next;
		i++;
	}
	return (max_postion);
}

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

