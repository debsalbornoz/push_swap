/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:39:04 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/15 14:39:33 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	if (a->size == 2)
		handle_two_elements(a);
	if (a->size == 4)
		push(a, b, 'a');
	if (a->size > 4)
	{
		push(a, b, 'a');
		push(a, b, 'a');
	}
}

void	handle_two_elements(t_stack *stack)
{
	int	first_element;
	int	second_element;

	first_element = stack->begin->value;
	second_element = stack->begin->next->value;
	if (first_element < second_element)
		return ;
	else
		swap(stack, 'a');
}

int find_target_node(t_stack *a, t_stack *b)
{
	 int target_value = a->begin->value;
    t_node *stack_b = b->begin;

    int closest_value = stack_b->value;
    int min_difference = target_value - closest_value;

    while (stack_b != NULL) {
        int difference = target_value - stack_b->value;
        if (difference * difference < min_difference * min_difference) {
            min_difference = difference;
            closest_value = stack_b->value;
        }
        stack_b = stack_b->next;
    }

    return closest_value;
}