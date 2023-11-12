/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:36:19 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/11 19:40:43 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (argc == 1 || check_args(argv))
		exit(1);
	initialize_stack(a,argv);
	rotate(a,'a');
	print_list(a);
	reverse_rotate(a, 'a');
	print_list(a);
	print_list(a);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
