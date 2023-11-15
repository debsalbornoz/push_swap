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
