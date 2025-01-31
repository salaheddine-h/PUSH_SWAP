/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:52 by salhali           #+#    #+#             */
/*   Updated: 2025/01/31 22:31:38 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  define INT_MIN	(-INT_MAX - 1)
#  define INT_MAX	2147483647

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int is_valid_number(char *str);


typedef struct s_node
{
    long data;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

#endif