/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:42:15 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 20:21:13 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest, char stack_name)
{
	t_node	*p_src;
	t_node	*p_dest;

	if (src->size == 0)
		return ;
	p_src = src->begin;
	p_dest = dest->begin;
	src->begin = p_src->next;
	if (src->size > 1)
		src->begin->prev = NULL;
	else
		src->end = NULL;
	p_src->next = p_dest;
	if (p_dest != NULL)
		p_dest->prev = p_src;
	dest->begin = p_src;
	src->size--;
	dest->size++;
	if (stack_name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
