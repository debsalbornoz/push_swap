/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:59:07 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:16 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*
The "check_args" function goes through all command-line arguments, using "is_number" to ensure each is a valid number.
It also checks for duplicates with the "duplicates" function and verifies that numeric values stay within acceptable
integer limits,using "max_int."
If there's an invalid number, duplicates, or values outside the allowed range, an error is reported.
.*/

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	if (duplicates(argv) || max_int(argv))
		return (1);
	return (0);
}

int	duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		if (argv[j] == NULL)
			break ;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		if (argv[j] == NULL)
		{
			i++;
			j = i + 1;
		}
	}
	return (0);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	max_int(char **argv)
{
	int			i;
	long int	int_max;
	long int	int_min;

	i = 1;
	int_max = MAX_INTEGER;
	int_min = MIN_INTEGER;
	while (argv[i] != NULL)
	{
		if (ft_custom_atoi(argv[i]) >= int_max
			|| ft_custom_atoi(argv[i]) <= int_min)
			return (1);
		i++;
	}
	return (0);
}
