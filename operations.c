/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:31:56 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 21:48:38 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time
*/

#include "push_swap.h"

void    swap(t_stack* l)
{
    int aux;
    
    if(l->size <= 1)
        return;
    aux = l->begin->value;
    l->begin->value = l->begin->next->value;
    l->begin->next->value = aux;
}

void ss(t_stack* a, t_stack* b)
{
    swap(a);
    swap(b);
}


void	push(t_stack *src, t_stack *dest)
{
	t_node	*p_src;
	t_node	*p_dest;
	t_node	*p_next;

    if(src->size == 0)
        return;
	p_src = src->begin;
	p_dest = dest->begin;
	p_next = src->begin->next;
	p_next->prev = NULL;
	src->begin = p_next;
	dest->begin = p_src;
	p_src->next = p_dest;
	p_dest->prev = p_src;
	src->size--;
	dest->size++;
}