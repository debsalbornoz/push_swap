/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:28:42 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:28:43 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Deallocates memory for a stack and its linked list nodes. 
It iterates through the list, frees each node, then frees the stack.*/

void	free_stack(t_stack **stack_ref)
{
	t_stack	*stack;
	t_node	*current_node;
	t_node	*next_node;

	stack = *stack_ref;
	current_node = stack->begin;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
	*stack_ref = NULL;
}

void	free_stacks(t_stack **a, t_stack **b)
{
		free_stack(a);
		free_stack(b);
}
