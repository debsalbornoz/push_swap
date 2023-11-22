/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:36:19 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 20:22:42 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*biggest;

	a = NULL;
	b = NULL;
	if (argc == 1 || check_args(argv))
		exit(1);
	initialize_stacks(&a, &b, argv);
	if (!stack_sorted(a))
	{
		biggest = find_biggest(a);
		ft_printf("%i\n", biggest->value);
	}
	//print_list(a);
	//print_list(b);
	destroy_stacks(&a, &b);
	return (0);
}
