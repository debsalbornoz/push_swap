/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:41:02 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:14 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->begin = NULL;
	stack->end = NULL;
	stack->size = 0;
	return (stack);
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

void	add_node(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if ((stack->size == 0) && (stack->begin == NULL) && (stack->end == NULL))
		stack->begin = new_node;
	else
	{
		stack->end->next = new_node;
		new_node->prev = stack->end;
	}
	stack->end = new_node;
	stack->size++;
}

void	initialize_stack(t_stack *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_node(a, atoi(argv[i]));
		i++;
	}
}

void	destroy_stack(t_stack **stack_ref)
{
	t_stack	*stack;
	t_node	*current_node;
	t_node	*next_node;

	stack = *stack_ref;
	current_node = stack->begin;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
	*stack_ref = NULL;
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
	write(1, "\n", 1);
}
