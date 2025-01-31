


#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*s;
	t_stack	*b;

	if(argc == 1)
		exit (EXIT_FAILURE);
	a = stack_();
	b = stack_();
	get_inpuut(a, b, argv + 1, argc -1);
	if(a->size ==3)
		sort_three(a);
	else fi (a->size == 5)
		naive_sort(a, b);
	else
		chunks_sort(a, b);
	free_stack(a);
	free_stack(b);
	exit (EXIT_SUCCESS);
}
