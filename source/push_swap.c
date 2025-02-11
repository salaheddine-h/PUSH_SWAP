/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/10 21:49:09 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int is_valid_number(char *str)
// {
//     int i;
//     long num;

//     i = 0;
//     if (!str || str[0] == '\0')
//         return (0);
//     if (str[i] == '-' || str[i] == '+')
//         i++;
//     num = atol(str);
//     if(num < INT_MIN || num > INT_MAX) //check is number kbiir mn range (int)
//         return(0);
//     while (str[i])
//     {
//         if (!ft_isdigit(str[i]))
//             return (0);
//         i++;
//     }
//     // Check duplicate
//     while (str[i])
//     {
//         if (str[i]) // L9ina duplicate
//             return (0);
//     }
//     return(1);
// }
// int is_valid_number(char *str) {
//     int i = 0;
//     if (str[i] == '-' || str[i] == '+')  // Allow negative & positive signs
//         i++;
//     while (str[i]) {
//         if (!isdigit(str[i]))  // Check wach ghir numbers
//             return (0);
//         i++;
//     }
//     return (1);
// }


int is_valid_number(char *str, t_node *stackA)
{
    int i;
    long num;
    t_node *temp;

    i = 0;
    if (!str || str[0] == '\0')
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    num = atol(str);
    if (num < INT_MIN || num > INT_MAX) // Check if number is out of range (int)
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    // ✅ Check Duplicate in stackA
    temp = stackA;
    while (temp)
    {
        if (temp->data== (int)num) // L9ina deja kayn f stackA
            return (0);
        temp = temp->next;
    }
    return (1);
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
            num = atoi(argv[i]); // Converti l int
            if(!is_valid_number(argv[i], stackA))// Check number & duplicate
            {
                write(1, "Error You Have Duplicate Number, 7salti \n", 42);
                return (1);
            }
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
