#include "push_swap.h"
#include <stdio.h>

/*Create stacks 'a' and 'b', and add all the command-line arguments to stack 'a',
 converting strings into numbers using the ft_atoi function. */

void	initialize_stacks(t_stack **a, t_stack **b, char **argv)
{
	int	i;

	i = 1;
	*a = create_stack();
	*b = create_stack();
	while (argv[i] != NULL)
	{
		add_node(*a, atoi(argv[i]));
		i++;
	}
}

/*For each node, this function sets the current_position attribute based on its position in the stack
and determines whether the node is above or below the median, setting the above_median attribute accordingly.*/

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

/*Determines target nodes in stack a for each node in stack b.
It iterates through nodes in b, finding the smallest node in a that is greater than the current node in b. 
If no such node is found, it selects the smallest node in a as the target.*/
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
			stack_b->target_node = find_min_value(a);
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

void	set_price(t_stack *a, t_stack *b)
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

void	init_nodes(t_stack **a, t_stack **b)
{
	get_relative_positions(*a);
	get_relative_positions(*b);
	set_target_node(*a, *b);
	set_price(*a, *b);
	set_cheapest(*b);

}