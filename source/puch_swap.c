/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puch_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/01 21:21:32 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// #include "../libft/libft.a"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// # define INT_MIN    (-INT_MAX - 1)
// # define INT_MAX    2147483647

// Function to check if character is digit
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
// Check if string is a valid number
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
// Function to create a new node in the stack
t_node *new_node(long data) //// Kat créer node jdida
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

t_node *get_last_node(t_node **stack)
{
    t_node *tmp;

    if (stack)
        return NULL;
    tmp = *stack;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return(tmp);
}
// Push function to add element to the stack
void push(t_node **stack, long data) //Katzid node jdida f stack:
{
    t_node *node = new_node(data); 
    t_node *tmp;
    tmp = get_last_node(stack);
    if (tmp)
        tmp->next = node;
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

    stackB = NULL; // Initialize stack B as empty Hitach stack B haso ikon khawi
    if(argc > 1)
    {
        check = is_valid_number(argv[1]); // Correction ici, 3adi ndir argv[1]
        while(check)
        {
            if (check)
            {
                num = atol(argv[1]);
                push(&stackB, num);
                write(1, "stackB siftna lih Data\n", 24);
            }
            else
            {
                    write(1, "Invalid number\n", 15);
            }
            print_stack(&stackB);
            return (0);
        }
    }
    else
        write(1, "Kol m3ahom ou 7di mnhom\n", 25);
        write(1, "T3am kayn ou lghdar kayn\n", 26);
    return(0);
}