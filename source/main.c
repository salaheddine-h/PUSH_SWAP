/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/15 15:14:32 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stackA;
    t_node  *stackB;
    long num;
    int i;

    stackA = NULL;
    stackB = NULL;
    if (argc > 1)
    {
        i = 1;
        while (i < argc)  //Loop through arguments
        {
            num = atol(argv[i]);
            if (!is_valid_number(argv[i], stackA))  //Ba9i 3ndi mochkiL hna dyal atol
                return (write(2, "Error\n", 7),1);
            check_dup(&stackA, num);
            push_s(&stackA, num);
            push_s(&stackB, num);

            i++;
        }
        print_stack(&stackA);
        printf("############\n");
        print_stack(&stackB);
    }
    else
    {
        write(2, "Error\n", 7);  //Proper error message
        exit(EXIT_FAILURE);
    }
    return (0);
}

