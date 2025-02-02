/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/02 13:51:43 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// # define INT_MIN    (-INT_MAX - 1)
// # define INT_MAX    2147483647
// // #include "../libft/libft.a"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    long data;
    struct s_node *next;
} t_node;

int ft_isdigit(int arg)
{
    if (arg >= '0' && arg <= '9')
        return (1);
    else
        return (0);
}
int is_valid_number(char *str)
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
    return (1);
}
t_node *new_node(long data) 
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

int	main(int argc, char **argv)
{
    t_node *stackB;
    int     check;
    long    num;
    int i;

    i = 1;
    stackB = NULL; // Initialize stack B as empty Hitach stack B haso ikon khawi
    if(argc > 1)
    {
        while (i < argc) // Bach ndiro loop li ghatraverse argv[i] li kaynin
        {
            check = is_valid_number(argv[i]); // Correction ici, 3adi ndir argv[1]
            if (check)
            {
                num = atol(argv[i]);
                push(&stackB, num);
                write(1, "stackB siftna lih Data\n", 24);
            }
            else
            {
                    write(1, "Invalid number\n", 15);
            }
            print_stack(&stackB);
            i++;
        }
    }
    else
    {
        write(1, "Kol m3ahom ou 7di mnhom\n", 25);
        write(1, "T3am kayn ou lghdar kayn\n", 26);
    }
    return(0);
}
