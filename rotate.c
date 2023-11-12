#include "push_swap.h"

void	rotate(t_stack *src)
{
	t_node	*p_begin;
	t_node	*p_next;
        if (src->begin != NULL && src->begin->next != NULL)
    {
		p_begin = src->begin;
		p_next = src->begin->next;
		src->end->next = p_begin;
		p_begin->prev = src->end;
		src->end = p_begin;
		src->begin = p_next;
		src->begin->prev = NULL;
		src->end->next = NULL;
    }
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}