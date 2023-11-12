#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time
*/

void reverse_rotate(t_stack *stack)
{
    t_node  *p_begin;
    t_node  *p_end;
    
    p_begin = stack->begin;
    p_end = stack->end;
    stack->begin = p_end;
    stack->end = p_end->prev;
    p_begin->prev = p_end;
    p_end->next = p_begin;
    stack->begin->prev = NULL;
    stack->end->next = NULL;
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rr\n");
}