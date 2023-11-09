/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:41:02 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 21:28:30 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*l;

	l = (t_stack *)ft_calloc(1, sizeof(t_stack));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->value = value;
	return (node);
}

void	destroy_stack(t_stack **l_ref)
{
	t_stack	*l;
	t_node			*p;
	t_node			*aux;

	l = *l_ref;
	p = l->begin;
	aux = NULL;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux);
	}
	free(l);
	*l_ref = NULL;
}

int	list_is_empty(const t_stack *l)
{
	if ((l->size == 0) && (l->begin == NULL) && (l->end == NULL))
		return (1);
	else
		return (0);
}
