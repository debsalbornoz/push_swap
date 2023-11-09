/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:37:24 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 21:13:56 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_first(t_stack *l, int value)
{
	t_node	*p;

	p = create_node(value);
	p->next = l->begin;
	if (list_is_empty(l))
		l->end = p;
	else
		l->begin->prev = p;
	l->begin = p;
	l->size++;
}

void	print_list(t_stack *l)
{
	t_node	*p;

	p = l->begin;
	while (p != NULL)
	{
		ft_printf("%i\n", p->value);
		p = p->next;
	}
	write(1,"\n",1);
}

void	add_last(t_stack *l, int value)
{
	t_node	*q;

	q = create_node(value);
	if (list_is_empty(l))
		l->begin = q;
	else
	{
		l->end->next = q;
		q->prev = l->end;
	}
	l->end = q;
	l->size++;
}

void	create_stack_a(t_stack *l, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_last(l, atoi(argv[i]));
		i++;
	}
	print_list(l);
}
