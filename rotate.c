#include "push_swap.h"

void	rotate(t_stack *stack, char stack_name)
{
	t_node	*p_begin;
	t_node	*p_next;
	t_node	*p_end;
        if (stack->begin != NULL && stack->begin->next != NULL)
    {
		p_begin = stack->begin;
		p_next = stack->begin->next;
		p_end = stack->end;
		p_end->next = p_begin;
		p_begin->prev = p_end;
		stack->end = p_begin;
		stack->begin = p_next;
		
		stack->begin->prev = NULL;
		stack->end->next = NULL;
        if(stack_name == 'a')
            ft_printf("ra\n");
        if(stack_name == 'b')
            ft_printf("rb\n");
        if(stack_name == 'r')
            ft_printf("rb\n");    
                
    }
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a,'r');
	rotate(b,'r');
	ft_printf("rr\n");
}