/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:42:15 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:36:52 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The push function transfers the top element from one stack (src) to another stack (dest).
It first checks if the source stack has one or zero elements or if it is empty. If so, the function does nothing.
Otherwise, it moves the top element from the src stack to the top of the dest stack, updating pointers accordingly.
It also adjusts the size and end pointers for both stacks. Finally, it prints a message indicating the operation performed*/

void push(t_stack *src, t_stack *dest, char stack_name)
{
    if (src == NULL || dest == NULL || src->size <= 0 || src->begin == NULL)
        return;

    t_node *p_src = src->begin;
    src->begin = p_src->next;

    if (src->begin != NULL)
        src->begin->prev = NULL;

    p_src->next = dest->begin;

    if (dest->begin != NULL)
        dest->begin->prev = p_src;

    dest->begin = p_src;

    if (dest->size == 0)
    {
        dest->end = dest->begin;
        dest->end->next = NULL;
    }

    src->size--;
    dest->size++;

    if (stack_name == 'b')
        ft_printf("pb\n");
    else
        ft_printf("pa\n");
}
