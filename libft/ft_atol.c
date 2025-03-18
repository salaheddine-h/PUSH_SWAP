/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:11:53 by salhali           #+#    #+#             */
/*   Updated: 2025/03/11 00:27:22 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces_and_check_sign(const char **s)
{
	int	sign;

	sign = 1;
	while (**s && ((**s >= 9 && **s <= 13) || **s == ' '))
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
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
