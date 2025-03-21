/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:26 by salhali           #+#    #+#             */
/*   Updated: 2025/03/21 02:55:55 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		signe;
	long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
			if (signe == 1 && result > (INT_MAX / 10))
			{
				//freee** 
				exit(1);
			}
			if (signe == -1 && result > -(long)(INT_MIN / 10))
			{
				///free**
				exit(1);
			}
			result = result * 10 + (nptr[i] - '0');
			if (signe == 1 && result > INT_MAX)
					return (INT_MAX);
			if (signe == -1 && result > -(long)INT_MIN)
					return (INT_MIN);
			i++;
	}
	return ((int)(signe * result));
}
