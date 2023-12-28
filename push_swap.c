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

/*The function sorts the stack when it contains 3 elements. It identifies the maximum value in the stack using the find_max_value function. 
The goal is to place the maximum value at the last position. 
If the maximum value is at the first position, it performs a rotation. If it's at the second position, it performs a reverse rotation. 
If the maximum value is already at the last position, no action is taken. 
If the first two elements are in reverse order, it performs a swap operation. 
By the end of the function, the three elements are arranged in ascending order.*/

void tiny_sort(t_stack **a)
{
    if (a == NULL || *a == NULL || (*a)->begin == NULL) {
        return;
    }

    t_node *stack = (*a)->begin;
    t_node *highest_node = find_max_value(*a);

    if (highest_node == NULL)
        return;
    if (stack == highest_node)
        rotate(a, 'a');
	else if (stack->next == highest_node)
        reverse_rotate(a, 'a');
	stack = (*a)->begin;
    if (stack->next != NULL && stack->value > stack->next->value) {
        swap(a, 'a');
    }
}

void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{

	while ((*a)->begin != cheapest_node->target_node && (*b)->begin != cheapest_node)
		rr(a, b);
	get_relative_positions(*a);
	get_relative_positions(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{
	while ((*a)->begin != cheapest_node->target_node && (*b)->begin != cheapest_node)
		rrr(a, b);
	get_relative_positions(*a);
	get_relative_positions(*b);
}

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

void push_swap(t_stack **a, t_stack **b)
{
    t_node *smallest;

    while ((*a)->size > 3)
    {
        push(a, b, 'b');
        // Adicione impressões de debugging aqui
        //ft_printf("After push: Stack A: \n");
        //print_list(*a);
       // ft_printf("Stack B: \n");
       // print_list(*b);
    }

    tiny_sort(a);
    while ((*b)->begin != NULL)
    {
        init_nodes(a, b);
        move_nodes(a, b);
       // ft_printf("After move_nodes: Stack A: \n ");
        //print_list(*a);
    	//ft_printf("Stack B: \n");
       // print_list(*b);
    }

    get_relative_positions(*a);
    smallest = find_min_value(*a);

    if (smallest->above_median)
        while ((*a)->begin != smallest)
        {
            rotate(a, 'a');
            // Adicione impressões de debugging aqui
            //ft_printf("After rotate: Stack A:\n ");
            //print_list(*a);
            //ft_printf("Stack B: \n ");
            //print_list(*b);
        }
    else
        while ((*a)->begin != smallest)
        {
            reverse_rotate(a, 'a');
            // Adicione impressões de debugging aqui
            //ft_printf("After reverse_rotate: Stack A: \n ");
            //print_list(*a);
            //ft_printf("Stack B: \n ");
            //print_list(*b);
        }
}
