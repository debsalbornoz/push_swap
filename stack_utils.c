/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:36:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 20:21:34 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_stack *node)
{
	long	smallest;
	t_node	*aux;
	t_node	*aux2;

	smallest = MAX_INTEGER;
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

t_node	*find_biggest(t_stack *node)
{
	t_node	*aux;
	t_node	*aux2;
	long	biggest;

	biggest = MIN_INTEGER;
	aux = node->begin;
	while (aux != NULL)
	{
		if (aux->value > biggest)
		{
			biggest = aux->value;
			aux2 = aux;
		}
		aux = aux->next;
	}
	return (aux2);
}

t_node *find_cheapest(t_node *stack)
{
	if(stack == NULL)
		return(NULL);
	while(stack != NULL)
	{
		if(stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return(NULL);
}


/*Checks if a stack is sorted in ascending order. It iterates through the stack,
 comparing each node's value with the value of the next node.*/

int	stack_sorted(t_stack *a)
{
	t_node	*aux;

	aux = a->begin;
	while (aux != NULL && aux->next != NULL)
	{
		if (aux->value > aux->next->value)
		{
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}
