/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:00:56 by salah             #+#    #+#             */
/*   Updated: 2025/02/25 12:24:04 by salhali          ###   ########.fr       */
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
            //free stack
            printf("ERROR");
            exit(1);//Safe to access `data`
        }
        tmp = tmp->next;
    }
}
int is_valid_number(char *str)
{
    int i;
    long num;
    // t_node *temp; //stackA dyali

    i = 0;
    if (!str || str[0] == '\0')
        return (0);
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 )
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
