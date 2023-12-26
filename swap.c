/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:31:56 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:13 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The swap function performs the swap of the two elements at the top of a stack.
If the stack has fewer than two elements, the function does nothing.
Otherwise, the values of the two elements at the top of the stack are exchanged.
The function prints a message indicating the operation performed.*/

void	swap(t_stack *stack, char stack_name)
{
	int	aux;

	if (stack->size <= 1)
		return ;
	aux = stack->begin->value;
	stack->begin->value = stack->begin->next->value;
	stack->begin->next->value = aux;
	if (stack_name == 'a')
		ft_printf("sa\n");
	else if (stack_name == 'b')
		ft_printf("sb\n");
	else if (stack_name == 's')
		return ;
}

//The function ss performs the simultaneous swap operation on two stacks (a and b).

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss");
}
