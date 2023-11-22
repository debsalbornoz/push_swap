/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:29:37 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:29:52 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
		handle_two_elements(a);
	else if (a->size == 4)
		push(a, b, 'a');
}

void	handle_two_elements(t_stack *a)
{
	if (a->begin->value > a->begin->next->value)
		swap(a, 'a');
	else
		return ;
}
