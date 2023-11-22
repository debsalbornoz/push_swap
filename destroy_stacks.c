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

void	destroy(t_stack **stack_ref)
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

void	destroy_stacks(t_stack **a, t_stack **b)
{
	destroy(a);
	destroy(b);
}