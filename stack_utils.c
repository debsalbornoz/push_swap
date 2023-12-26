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

/*Checks if a stack is sorted in ascending order. It iterates through the stack,
 comparing each node's value with the value of the next node.*/

int	stack_sorted(t_stack *a)
{
	t_node	*current_node;

	current_node = a->begin;
	while (current_node != NULL && current_node->next != NULL)
	{
		if (current_node->value > current_node->next->value)
		{
			return (0);
		}
		current_node = current_node->next;
	}
	return (1);
}

//The find_min_value function iterates through a stack to identify and return the node with the smallest value in the stack.

t_node	*find_min_value(t_stack *node)
{
	long	min_value;
	t_node	*current_node;
	t_node	*min_value_node

	min_value = MAX_INTEGER;
	current_node = node->begin;
	while (current_node != NULL)
	{
		if (current_node->value < smallest)
		{
			min_value = current_node->value;
			min_value_node = current_node;
		}
		current_node = current_node->next;
	}
	return (min_value_node);
}

//The find_max_value function iterates through a stack to identify and return the node with the biggest value in the stack.

t_node	*find_max_value(t_stack *node)
{
	t_node	*current_node;
	t_node	*max_value_node;
	long	max_value;

	max_value = MIN_INTEGER;
	current_node = node->begin;
	while (current_node != NULL)
	{
		if (current_node->value > max_value)
		{
			max_value = current_node->value;
			max_value_node = current_node;
		}
		current_node = current_node->next;
	}
	return (max_value_node);
}

/*The find_cheapest function searches for a node in a stack of elements, where each node has an attribute named cheapest. 
It returns the first node in the stack with the cheapest attribute set to true*/

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

