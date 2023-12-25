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


