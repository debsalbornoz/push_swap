#include "push_swap.h"

void push_swap(t_stack *a, t_stack *b)
{
    if(a->size==1)
        return;
    else if(a->size == 2)
    handle_two_elements(a);
    else if(a->size == 4)
        push(a,b,'a');
}

void handle_two_elements(t_stack *a)
{
    if(a->begin->value > a->begin->next->value)
    swap(a,'a');
    else
        return;
}