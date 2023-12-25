#include "push_swap.h"
#include <stdio.h>

void	get_relative_positions(t_stack *stack)
{
	int	i;
	int	center;
	t_node *node = stack->begin;
	i = 0;
	if (stack == NULL)
		return ;
	center = stack->size / 2;
	while (node != NULL)
	{
		node->current_position = i;
		if (i <= center)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		++i;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_node	        *stack_a;
	t_node          *stack_b;
    t_node          *current_a;
    t_node	        *target_node;
	long			best_match;

    stack_a = a->begin;
    stack_b = b->begin;
	while (stack_b != NULL)
	{
		best_match = MAX_LONG;
		current_a = stack_a;
		while (current_a != NULL)
		{
			if (current_a->value > stack_b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (MAX_LONG == best_match)
			stack_b->target_node = find_smallest(a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void print_target_nodes(t_stack *b)
{
    t_node *current_b = b->begin;

    printf("Target Nodes:\n");

    while (current_b != NULL)
    {
        printf("Node value: %d, Target Node value: %d\n", current_b->value, current_b->target_node->value);
        current_b = current_b->next;
    }

    printf("\n");
}

void	init_nodes(t_stack *a, t_stack *b)
{
	get_relative_positions(a);
	get_relative_positions(b);
	set_target_node(a, b);
}