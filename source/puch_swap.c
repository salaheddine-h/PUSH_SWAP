/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puch_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/01/31 22:30:21 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // #include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#  define INT_MIN	(-INT_MAX - 1)
#  define INT_MAX	2147483647

// int	ft_isdigit(int arg)
// {
// 	if (arg >= '0' && arg <= '9')
// 		return (1);
// 	else
// 		return (0);
// }
// int is_valid_number(char *str) //parsing dyal input
// {
//     int i;
//     long num;

//     i = 0;
//     if (!str || str[0] == '\0')
//         return (0);
//     if (str[i] == '-' || str[i] == '+')
//         i++;
//     while (str[i])
//     {
//         if (!ft_isdigit(str[i]))
//             return (0);
//         i++;
//     }
//     num = atol(str);
//     if(num < INT_MIN || num > INT_MAX)
//         return(0);
//     return (1);
// }
int	main(int argc, char **argv)
{
    t_stack stackB;
    int check;
    long    num;

    stackB = = {NULL}; // Initialize stack B as empty Hitach stack B haso ikon khawi
    if(argc > 1)
    {
        check = is_valid_number(argv[1]); // Correction ici, 3adi ndir argv[1]
        if (check)
        {
            num = atol(argv[1]);
            push(&stackB, num);
            write(1, "Valid number\n", 13);
        }
        else
        {
                write(1, "Invalid number\n", 15);
        }
        return (0);    
    }
    else
        write(1, "Kol m3ahom ou 7di mnhom\n", 25);
        write(1, "T3am kayn ou lghdar kayn\n", 26);
    return(0);
}


// Function to check if character is digit
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
    if(num < INT_MIN || num > INT_MAX)
        return(0);
    return (1);
}

// Function to create a new node in the stack
t_node *new_node(long data)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// Push function to add element to the stack
void push(t_stack *stack, long data)
{
    t_node *node = new_node(data);
    if (node)
    {
        node->next = stack->top;
        stack->top = node;
    }
}

// Function to check and push valid number from argv[1] to stack B
int main(int argc, char **argv)
{
    t_stack stackB = {NULL};  // Initialize stack B as empty
    // t_node  stackA
    int check;

    if (argc > 1)
    {
        check = is_valid_number(argv[1]);  // Check if argv[1] is a valid number
        
        if (check)
        {
            // If valid, push the number to stack B
            long num = atol(argv[1]);
            push(&stackB, num);
            write(1, "Number pushed to stack B\n", 25);
        }
        else
        {
            write(1, "Invalid number\n", 15);
        }

        return (0);
    }
    else
    {
        write(1, "Kol m3ahom ou 7di mnhom\n", 25);
        write(1, "T3am kayn ou lghdar kayn\n", 26);
    }
    return (0);
}
