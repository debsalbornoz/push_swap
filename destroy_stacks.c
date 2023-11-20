#include "push_swap.h"

void destroy(t_stack **stack_ref)
{
    t_stack *stack = *stack_ref;
    t_node *current_node;
	t_node *next_node;

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

void destroy_stacks(t_stack **a, t_stack   **b)
{
    destroy(a);
    destroy(b);
}
