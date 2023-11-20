#include "push_swap.h"

void push(t_stack *src, t_stack *dest)
{
	t_node	*p_src;
	t_node	*p_dest;
    if (src->size <= 1 || src->begin == NULL)
        return;
    p_src = src->begin;
    p_dest = dest->begin;
    src->begin = p_src->next;
    src->begin->prev = NULL;
    p_src->next = p_dest;
    if (p_dest != NULL) {
        p_dest->prev = p_src;
    }
    dest->begin = p_src;

    src->size--;
    dest->size++;
}