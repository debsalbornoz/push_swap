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

void	push(t_stack *src, t_stack *dest, char stack_name)
{
	t_node	*p_src;
	t_node	*p_dest;

	if (src->size <= 1 || src->begin == NULL)
		return ;
	p_src = src->begin;
	p_dest = dest->begin;
	src->begin = p_src->next;
	src->begin->prev = NULL;
	p_src->next = p_dest;
	if (p_dest != NULL)
		p_dest->prev = p_src;
	dest->begin = p_src;
	if (dest->size == 0)
	{
		dest->end = dest->begin;
		dest->end->next = NULL;
	}
	src->size--;
	dest->size++;
	if (stack_name == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}
