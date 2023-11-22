/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:36:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:36:14 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_stack *node)
{
	long	smallest;
	t_node	*aux;
	t_node	*aux2;

	smallest = MAX_INTEIRO;
	aux = node->begin;
	while (aux != NULL)
	{
		if (aux->value < smallest)
		{
			smallest = aux->value;
			aux2 = aux;
		}
		aux = aux->next;
	}
	return (aux2);
}
