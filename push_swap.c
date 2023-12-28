/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:29:37 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 19:29:52 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Implements the push swap algorithm to sort a stack (a) using an auxiliary stack (b).
It performs initial pushes, sorts small groups of elements, moves nodes back to stack a, and arranges the final order of elements,
focusing on minimizing the number of operations for an efficient sorting process.*/

void push_swap(t_stack **a, t_stack **b)
{
    t_node *min_value_node;

    while ((*a)->size > 3)
        push(a, b, 'b');
    tiny_sort(a);
    while ((*b)->begin != NULL)
    {
        initialize_stacks(a, b);
        move_nodes(a, b);
    }

    initialize_positions(*a);
    min_value_node = find_min_value(*a);

    if (min_value_node->above_median)
        while ((*a)->begin != min_value_node)
            rotate(a, 'a');
    else
        while ((*a)->begin != min_value_node)
            reverse_rotate(a, 'a');
}

/*Performs the necessary operations to move the cheapest node from stack 'b' to stack 'a'
while maintaining the target node's relative position.
It considers whether both the cheapest node and its target node are above or below the median,
applying appropriate rotation or reverse rotation operations. 
Finally, it completes the rotation steps and executes the push operation.*/

void	move_nodes(t_stack **a, t_stack **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node == NULL || cheapest_node->target_node == NULL) 
    	return;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	push(b, a, 'b');
}

/*Rotates both stacks simultaneously using the rr operation until the target node of the cheapest node
in stack b aligns with the cheapest node in stack a. 
After the rotation, it updates the relative positions of the nodes in both stacks.*/

void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{

	while ((*a)->begin != cheapest_node->target_node && (*b)->begin != cheapest_node)
		rr(a, b);
	initialize_positions(*a);
	initialize_positions(*b);
}

/*Performs a combined reverse rotation operation on both stacks until the target node
of the cheapest node in stack b aligns with the cheapest node in stack a. 
This function uses the rrr operation, which is a simultaneous reverse rotation of both stacks.
After the reverse rotation, it updates the relative positions of the nodes in both stacks.*/

void	reverse_rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{
	while ((*a)->begin != cheapest_node->target_node && (*b)->begin != cheapest_node)
		rrr(a, b);
	initialize_positions(*a);
	initialize_positions(*b);
}

/*The finish_rotation function aligns the top of a given stack (stack) with a specified target node (top_node).
It adjusts the stack's orientation by either rotating or reverse rotating, depending on whether the target node is above or below the median.
The direction of rotation is determined by the stack_name parameter, representing either stack 'a' or 'b'. 
The goal is to position the specified node as the new top element in the stack.*/

void	finish_rotation(t_stack **stack, t_node *top_node, char stack_name)
{

	while ((*stack)->begin != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate(stack, 'a');
			else
				reverse_rotate(stack,'a');
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate(stack,'b');
			else
				reverse_rotate(stack,'b');
		}
	}
}



