#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

// Check Parsing
int		check_arguments(char **argv);
int		validate_number(const char *str);
int		check_multiple_numbers(const char *arg);
int		check_single_number(const char *arg);
int		contains_only_spaces(char *str);


// Utils
void	ft_error(char *str);
void	ft_free(char **str);
void	free_stack(t_list **stack);
void	print_stack(t_list **stack);
void	free_stack_and_exit(t_list **stack, char *msg, int true);

// Initialize Stack
void	initialize_stack(char **argv, t_list **stack_a);
void	initialize_stack_1(char **argv, int index, t_list **stack_a);
int		check_duplicates(t_list *stack);
int		check_stack_order(t_list **stack);

// Stack Instruction
int		swap(t_list **stack);
int		swap_stack_a(t_list **stack_a);
int		swap_stack_b(t_list **stack_b);
int		swap_both_stack(t_list **stack_a, t_list **stack_b);

int		push(t_list **dest_stack, t_list **src_stack);
int		push_stack_a(t_list **stack_a, t_list **stack_b);
int		push_stack_b(t_list **stack_a, t_list **stack_b);

int		rotate_stack(t_list **stack);
int		rotate_stack_a(t_list **stack_a);
int		rotate_stack_b(t_list **stack_b);
int		rotate_both_stack(t_list **stack_a, t_list **stack_b);

int		reverse_rotate_stack(t_list **stack);
int		reverse_rotate_stack_a(t_list **stack_a);
int		reverse_rotate_stack_b(t_list **stack_b);
int		reverse_rotate_both_stack(t_list **stack_a, t_list **stack_b);

// Sort Algorithms
void	small_sort(t_list **stack_a, t_list **stack_b);
void	sort_3_number(t_list **stack_a);
void	sort_4_number(t_list **stack_a, t_list **stack_b);
void	sort_5_number(t_list **stack_a, t_list **stack_b);

void	move_element_to_top(t_list **stack_a, int postion);
int		min_element_postion(t_list **stack_a);
int		max_element_postion(t_list *stack_a);

int		*sorted_stack_in_tab(t_list **stack_a, int stack_size);
int		*bubble_sort(int *tab, int size);
int		reverse_sorted_percentage(t_list *stack);

void	big_sort(t_list **stack_a, t_list **stack_b);
void	optimized_big_sort(t_list **stack_a, t_list **stack_b);
void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b);
void	push_elements_to_stack_b(t_list **stack_a, t_list **stack_b, int *tab,
			int range);

#endif
