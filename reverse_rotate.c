#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time
*/

void reverse_rotate(t_stack *stack, char stack_name)
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
    if(stack_name == 'a')
        ft_printf("rra\n");
    if(stack_name == 'b')
        ft_printf("rrb\n");
    if(stack_name == 'r')
        return;    
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a,'r');
    reverse_rotate(b,'r');
    ft_printf("rr\n");
}