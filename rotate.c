/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:31:57 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:03 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char stack_name)
{
	t_node	*p_begin;
	t_node	*p_next;

	if (stack->begin != NULL && stack->begin->next != NULL)
	{
		p_begin = stack->begin;
		p_next = stack->begin->next;
		stack->end->next = p_begin;
		p_begin->prev = stack->end;
		stack->end = p_begin;
		stack->begin = p_next;
		stack->begin->prev = NULL;
		stack->end->next = NULL;
		if (stack_name == 'a')
			ft_printf("ra\n");
		if (stack_name == 'b')
			ft_printf("rb\n");
		if (stack_name == 'r')
			ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}
