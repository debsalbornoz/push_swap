/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:31:56 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:13 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The swap function performs the swap of the two elements at the top of a stack.
If the stack has fewer than two elements, the function does nothing.
Otherwise, the values of the two elements at the top of the stack are exchanged.
The function prints a message indicating the operation performed.*/

void swap(t_stack **stack, char stack_name)
{
    if (*stack == NULL || (*stack)->size <= 1 || (*stack)->begin == NULL || (*stack)->begin->next == NULL)
        return;

    t_node *first = (*stack)->begin;
    t_node *second = first->next;

    // Remover os nós da frente
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;

    // Adicionar os nós removidos à frente
    second->next = first;
    second->prev = NULL;
    first->prev = second;

    // Atualizar o início da pilha
    (*stack)->begin = second;

    // Atualizar o final da pilha se necessário
    if (first == (*stack)->end)
        (*stack)->end = first;

    if (stack_name == 'a')
        ft_printf("sa\n");
    else if (stack_name == 'b')
        ft_printf("sb\n");
    else if (stack_name == 's')
        return;
}

//The function ss performs the simultaneous swap operation on two stacks (a and b).

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss");
}
