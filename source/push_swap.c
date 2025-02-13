/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:45 by salhali           #+#    #+#             */
/*   Updated: 2025/02/13 12:48:52 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_dup(t_node **stack, long num)
{
    t_node *tmp;

    if (!stack || !*stack)  //Check if stack exists
    {
        return;
    }
    tmp = *stack;
    while (tmp)  //Loop while `tmp` is not NULL
    {
        if (tmp->data == num)
        {
            // print_stack(stack);
            printf("ERROR");
            exit(1);//Safe to access `data`
        }
        tmp = tmp->next;
    }
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
    num = atoi((char *)str);
    if (num < INT_MIN || num > INT_MAX) // Check if number is out of range (int)
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_node  *stackA;
    t_node  *stackB;
    int num;
    int i;

    stackA = NULL;
    stackB = NULL;
    if (argc > 1)
    {
        i = 1;
        while (i < argc)  //Loop through arguments
        {
            num = atoi(argv[i]);
            if (!is_valid_number(argv[i], stackA))  //Validate input number
                return (write(2, "Error\n", 7),1);
            check_dup(&stackA, num);
            push(&stackA, num);
            // sa(&stackA);
            // sb(&stackA);
            // ss(&stackA, &stackB);
            i++;
        }
        print_stack(&stackA);
    }
    else
    {
        write(2, "Error\n", 7);  //Proper error message
        return (1);
    }
    return (0);
}

