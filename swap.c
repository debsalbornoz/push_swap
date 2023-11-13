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

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss");
}
