/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:31:57 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:36:03 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function performs a rotation operation on a stack represented by the t_stack structure.
It checks if the stack is non-empty and has more than one element. 
If so, it rotates the elements in the stack by updating pointers and prints a message indicating the operation performed*/

void	rotate(t_stack *stack, char stack_name)
{
	t_node	*p_begin;
	t_node	*p_next;
	t_node	*p_end;

	if (stack->begin != NULL && stack->begin->next != NULL)
	{
		p_begin = stack->begin;
		p_next = stack->begin->next;
		p_end = stack->end;
		p_end->next = p_begin;
		p_begin->prev = p_end;
		stack->end = p_begin;
		stack->begin = p_next;
		stack->begin->prev = NULL;
		stack->end->next = NULL;
		if (stack_name == 'a')
			ft_printf("ra\n");
		if (stack_name == 'b')
			ft_printf("rb\n");
		if (stack_name == 'r')
			return;
	}
}

/*Performs a double rotation on two stacks (a and b) by calling the rotate function*/
void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}
