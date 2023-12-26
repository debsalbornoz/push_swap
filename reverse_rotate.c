/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:31:48 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:35:56 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The reverse_rotate function performs a reverse rotation operation on a stack. 
It checks if the stack has one or zero elements, and if so, it does nothing.
Otherwise, it updates pointers to reverse the order of elements in the stack and prints a message indicating the operation performed */

void	reverse_rotate(t_stack *stack, char stack_name)
{
	t_node	*p_begin;
	t_node	*p_end;

	if (stack->size <= 1)
		return ;
	p_begin = stack->begin;
	p_end = stack->end;
	stack->begin = p_end;
	stack->end = p_end->prev;
	p_begin->prev = p_end;
	p_end->next = p_begin;
	stack->begin->prev = NULL;
	stack->end->next = NULL;
	if (stack_name == 'a')
		ft_printf("rra\n");
	if (stack_name == 'b')
		ft_printf("rrb\n");
	if (stack_name == 'r')
		return ;
}

/* Performs a double reverse rotation on two stacks by calling the reverse_rotate function for both.*/
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'r');
	reverse_rotate(b, 'r');
	ft_printf("rr\n");
}
