/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:35:52 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 20:37:47 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

linked_list	*create_linked_list(void)
{
	linked_list	*l;

	l = (linked_list *)ft_calloc(1, sizeof(linked_list));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}

node	*create_node(int value)
{
	node	*snode;

	snode = (node *)ft_calloc(1, sizeof(snode));
	snode->prev = NULL;
	snode->next = NULL;
	snode->value = value;
	return (snode);
}

void	destroy_linked_list(linked_list **l_ref)
{
	linked_list	*l;
	node		*p;
	node		*aux;

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

int	list_is_empty(const linked_list *l)
{
	if ((l->size == 0) && (l->begin == NULL) && (l->end == NULL))
		return (1);
	else
		return (0);
}

void	remove_node(linked_list *l, int value)
{
	node	*p;
	node	*p;
	else	p;

	if (!list_is_empty(l))
	{
		if (l->begin->value == value)
		{
			p = l->begin;
			l->begin = p->next;
			if (l->end == p)
				l->end = NULL;
			else
				l->begin->prev = NULL;
			free(p);
			l->size--;
		}
		else
		{
			p = l->begin->next;
			while (p != NULL)
			{
				if (p->value == value)
				{
					if (l->end == p)
					{
						l->end = p->prev;
						l->end->next = NULL;
					}
					else
					{
						p->prev->next = p->next;
						p->next->prev = p->prev;
					}
				}
				free(p);
				p = NULL;
				l->size--;
				p = p->next;
			}
		}
	}
}
