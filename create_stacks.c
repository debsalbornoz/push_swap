/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:41:02 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 20:03:31 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Establish an initial stack with a node containing pointers to the first and last nodes of the list,
along with the size. Return a pointer to this initial node.*/

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->begin = NULL;
	stack->end = NULL;
	stack->size = 0;
	return (stack);
}

// Creates and returns a new node for a linked list data structure.

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->value = value;
	return (node);
}

/* Add a new node to the end of a linked list ,updating pointers and size accordingly.
If the stack is empty, it sets the start pointer. Otherwise, it connects the new node
to the current last node,  updating the end pointer and incrementing the stack size.
The new node is assigned an index indicating its position in the stack.*/

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
	new_node->index = stack->size;
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
