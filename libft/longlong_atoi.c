/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlong_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:11:53 by salhali           #+#    #+#             */
/*   Updated: 2025/03/20 01:47:55 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces_and_check_sign(const char **s)
{
	int	sign;
	int	i = 0;
	char	*str;

	sign = 1;
	str = (char*)*s;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (sign);
}

long long	convert_to_longlong(const char *s, int sign)
{
	long long	reslt;

	reslt = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		if (reslt > (LLONG_MAX / 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		if (reslt == (LLONG_MAX / 10) && (*s - '0') > (LLONG_MAX % 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		reslt = reslt * 10 + (*s - '0');
		s++;
	}
	return (sign * reslt);
}

long long	longlong_atoi(const char *s)
{
	int	sign;

	sign = skip_spaces_and_check_sign(&s);
	return (convert_to_longlong(s, sign));
}
