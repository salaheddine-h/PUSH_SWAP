/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/25 12:24:35 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stackA;
    t_node  *stackB;
    long    num;
    int i;

    stackA = NULL;
    stackB = NULL;
    if (argc > 1)
    {
        i = 1;
        while (i < argc)  //Loop through arguments
        {
            if (!is_valid_number(argv[i])) //Ba9i 3ndi mochkiL hna dyal atol
                return (write(2, "Error\n", 7),1); // free stack
            num = ft_atoi(argv[i]);
            if (num > INT_MAX || num < INT_MIN)
                return (write(2, "Error\n", 7),1); // free stack
            check_dup(&stackA, num);
            push_s(&stackA, num);
            // push_s(&stackB, num);
            i++;
        }
        print_stack(&stackA);
        // print_stack(&stackA);
        // printf("############\n");
        // print_stack(&stackB);
    }
    else
    {
        write(2, "Error\n", 7);
        exit(EXIT_FAILURE);
    }
    return (0);
}

