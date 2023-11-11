/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:36:19 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/11 14:50:28 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (argc == 1)
		exit(1);
	if (verify(argv) == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	create_stack_a(a, argv);
	create_stack_a(b, argv);
	push(b, a);
	print_list(a);
	print_list(b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
