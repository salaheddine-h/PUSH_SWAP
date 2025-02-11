/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/11 19:25:21 by salhali          ###   ########.fr       */
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

void    check_dup(t_node **stack, long num)
{

    t_node *tmp;

    if (!stack || !*stack)  // ✅ Check if stack exists
    {
        return;
    }

    tmp = *stack;
    while (tmp)  // ✅ Loop while `tmp` is not NULL
    {
        if (tmp->data == num)
        {
            // print_stack(stack);
            printf("DUPLICATED NUMBER");
            exit(1);// ✅ Safe to access `data`
        }
        tmp = tmp->next;
    }
    // return(1);                
}

int is_valid_number(char *str, t_node *stack)
{
    int i;
    long num;
    t_node *temp; //stackA dyali

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
    // printf("Hna mochkiL");

        // print_stack(&stack);
    //Check Duplicate in stackA
    // temp = stackA;
    // while (temp)
    // {
    //     // printf("->%ld\n",temp->data); //just check
    //     if (temp->data == num) // L9ina deja kayn f stackA
    //         return (0);
    //     temp = temp->next;
    // }
    return (1);
}

int main(int argc, char **argv)
{
    t_node *stackA = NULL;  // ✅ Initialize stackA
    int num;
    int i;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)  // ✅ Loop through arguments
        {
            num = atol(argv[i]);
            printf("%ld", num);  // ✅ Convert string to long first

            if (!is_valid_number(argv[i], stackA))  // ✅ Validate input number
            {
                write(2, "Error\n", 6);
                return (1);
            }
            check_dup(&stackA, num);
            push(&stackA, num);  // ✅ Push number to stack
            i++;
        }
        print_stack(&stackA);  // ✅ Debugging: print stack
    }
    else
    {
        write(2, "Error\n", 6);  // ✅ Proper error message
        return (1);
    }
    return (0);
}

