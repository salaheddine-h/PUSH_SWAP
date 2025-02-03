/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/02 21:21:30 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str, t_node *stack)
{
    int i;
    long num;

    i = 0;
    if (!str || str[0] == '\0')
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    num = atol(str);
    if(num < INT_MIN || num > INT_MAX) //check is number kbiir mn range (int)
        return(0);
    //Check duplicate
    while (stack)
    {
        if (stack->data == num) // L9ina duplicate
            return (0);
        stack = stack->next;
    }
    return(1);
}
t_node  *new_node(long data) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

t_node *get_last_node(t_node **stack)
{
    t_node *tmp;

    if (!stack)
        return NULL;
    tmp = *stack;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return(tmp);
}
// Push function to add element to the stack
void push(t_node **stack, long data)
{
    t_node *node;
    // t_node *tmp;

    node = new_node(data); 
    // tmp = get_last_node(stack);
    if (!node)
    node->next = *stack;
    *stack = node;
}

void print_stack(t_node **stack)
{
    t_node *tmp;

    if(!stack)
        return ;
    tmp = *stack;
    while (tmp)
    {
        printf("-- %ld -- \n",tmp->data);
        tmp = tmp->next;
    }
}
int main(int argc, char **argv)
{
    t_node *stackA;
    int num;
    int i;
    
    i = 1;
    stackA = NULL;
    if (argc > 1)
    {
        while (i < argc) // Bach ndiro loop li ghatraverse argv[i] li kaynin
        {
            if (!is_valid_number(argv[i], stackA)) // Check number & duplicate
                return (write(1, "Error\n", 6), 1);

            num = atoi(argv[i]); // Converti l int
            push(&stackA, num); // Zido f stackA
            write(1, "stackB siftna lih Data\n", 24);
            print_stack(&stackA);
            i++;
        }
    }
    else
    {
        write(1, "Kol m3ahom ou 7di m3ahom\n", 26);
        write(1, "T3am kayn ou lghdar kayn\n", 25);
    }
    return (0);
}
