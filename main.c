/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:36:19 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 21:31:34 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_linked_list	*l;

	l = create_linked_list();
	if (argc == 1)
		exit(1);
	if (verify(argc, argv) == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	create_stackb(l, argv);
	destroy_linked_list(&l);
	return (0);
}
