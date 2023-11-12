#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*p_src;
	t_node	*p_dest;
	t_node	*p_next;

	if (src->size == 0)
		return ;
	p_src = src->begin;
	p_dest = dest->begin;
	p_next = src->begin->next;
	p_next->prev = NULL;
	src->begin = p_next;
	dest->begin = p_src;
	p_src->next = p_dest;
	p_dest->prev = p_src;
	src->size--;
	dest->size++;
}
