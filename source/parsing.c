/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:00:56 by salah             #+#    #+#             */
/*   Updated: 2025/02/15 15:01:15 by salah            ###   ########.fr       */
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
    // t_node *temp; //stackA dyali

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
