#include "push_swap.h"
#include <stdio.h>

/*The initialize_stacks function establishes initial conditions for two stacks by assigning the current position of each node,
determining whether the node is above the median, defining target nodes for stack b in stack a, 
calculating push prices, and marking the cheapest node in stack b.*/

void	initialize_stacks(t_stack **a, t_stack **b)
{
	initialize_positions(*a);
	initialize_positions(*b);
	define_target_node(*a, *b);
	calculate_push_price(*a, *b);
	set_cheapest(*b);

}

/*For each node, this function sets the current_position attribute based on its position in the stack
and determines whether the node is above or below the median, setting the above_median attribute accordingly.*/

void	initialize_positions(t_stack *stack)
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

/*Determines target nodes in stack a for each node in stack b.
It iterates through nodes in 'b', finding the smallest node in 'a' that is greater than the current node in 'b'. 
If no such node is found, it selects the smallest node in 'a' as the target.*/

void	define_target_node(t_stack *a, t_stack *b)
{

	t_node          *stack_b;
    t_node          *current_a;
    t_node	        *target_node;
	long			target_value;

    stack_b = b->begin;
	while (stack_b != NULL)
	{
		target_value = MAX_LONG;
		current_a = a->begin;
		while (current_a != NULL)
		{
			if (current_a->value > stack_b->value && current_a->value < target_value)
			{
				target_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (MAX_LONG == target_value)
			stack_b->target_node = find_min_value(a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

/*Calculates and assigns push prices to each node in stack b based on its current position,
 whether it is above or below the median, and the position of its target node in stack 'a'.*/

void	calculate_push_price(t_stack *a, t_stack *b)
{
	t_node *stack_b;

	stack_b = b->begin;
	while (stack_b)
	{
		stack_b->push_price = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_price = b->size - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->push_price += stack_b->target_node->current_position;
		else
			stack_b->push_price += a->size - (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}

/* Identifies the node with the lowest push price in stack b and marks it as the cheapest. */

void	set_cheapest(t_stack *b)
{
	long			best_match;
	t_node			*best_match_node;
	t_node			*stack_b;

	stack_b = b->begin;
	if (stack_b == NULL )
		return ;
	best_match = MAX_LONG;
	while (stack_b)
	{
		if (stack_b->push_price < best_match)
		{
			best_match = stack_b->push_price;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest = true;
}

