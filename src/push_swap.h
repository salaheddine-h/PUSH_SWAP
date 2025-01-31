



# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//----------- Stack_Function -----------//
t_stack	*stack_init(void);
t_node	*new_elem(int	data);
void	push_elem(t_stack *stack, t_node *elem);
void	push_elem_bottom(t_stack *stack, t_node *elem);
void	pop_elem(t_stack *stack);

