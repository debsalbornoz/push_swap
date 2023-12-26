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

/*The function sorts the stack when it contains 3 elements. It identifies the maximum value in the stack using the find_max_value function. 
The goal is to place the maximum value at the last position. 
If the maximum value is at the first position, it performs a rotation. If it's at the second position, it performs a reverse rotation. 
If the maximum value is already at the last position, no action is taken. 
If the first two elements are in reverse order, it performs a swap operation. 
By the end of the function, the three elements are arranged in ascending order.*/

void tiny_sort(t_stack **a) {
    if (a == NULL || *a == NULL || (*a)->begin == NULL) {
        return;
    }

    t_node *stack = (*a)->begin;
    t_node *highest_node = find_max_value(*a);

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
