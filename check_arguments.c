/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:10:17 by salhali           #+#    #+#             */
/*   Updated: 2025/03/08 21:10:19 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_only_spaces(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str) == 0)
			return (0);// kayn chi haja mkhtalfa 3la spaces
		str++;
	}
	return (1);//return 1 ila kan kolchi space
}

int	validate_number(const char *str)
{
	int			i;
	int long	num;

	if (str[0] == '\0')
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1]))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int	check_single_number(const char *arg)
{
	if (validate_number(arg) == 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}

int	check_multiple_numbers(const char *arg)
{
	char	**args;
	int		k;

	args = ft_split(arg, ' ');
	if (args == NULL)
		ft_error("Error");
	k = 0;
	while (args[k])
	{
		if (validate_number(args[k]) == 1)
		{
			ft_putendl_fd("Error", 2);
			ft_free(args);
			return (1);
		}
		k++;
	}
	ft_free(args);
	return (0);
}

int	check_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (contains_only_spaces(argv[i]) == 1)
			ft_error("Error");
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			if (check_single_number(argv[i]) == 1)
				return (1);
		}
		else
		{
			if (check_multiple_numbers(argv[i]) == 1)
				return (1);
		}
		i++;
	}
	return (0); //function radi tkon == 0 ilaa kan kolchi valid
}

