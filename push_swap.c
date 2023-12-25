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

void tiny_sort(t_stack **a) {
    if (a == NULL || *a == NULL || (*a)->begin == NULL) {
        return;
    }

    t_node *stack = (*a)->begin;
    t_node *highest_node = find_biggest(*a);

    if (highest_node == NULL)
        return;
    if (stack == highest_node)
        rotate(*a, 'a');
	else if (stack->next == highest_node)
        reverse_rotate(*a, 'a');
	stack = (*a)->begin;
    if (stack->next != NULL && stack->value > stack->next->value) {
        swap(*a, 'a');
    }
}

void push_swap(t_stack *a, t_stack  *b)
{
	while(a->size > 3)
	{
		push(a,b,'a');
	}
	if(a->size == 3)
		tiny_sort(&a);
}
// void	handle_five(t_stack_node **a, t_stack_node **b)
// {
// 	while (stack_len(*a) > 3)
// 	{
// 		init_nodes(*a, *b);
// 		finish_rotation(a, find_smallest(*a), 'a');
// 		pb(b, a, false);
// 	}
// }