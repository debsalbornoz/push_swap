#include "push_swap.h"

t_node  *find_smallest(t_stack   *node)
{
    long      smallest;
    smallest = MAX_INTEIRO;
    t_node  *aux;
    t_node  *aux2;
    aux = node->begin;
    while(aux != NULL)
    {
        if(aux->value < smallest)
        {
            smallest = aux->value;
            aux2 = aux;
        }
            
        aux = aux->next;
    }
    return(aux2);
}

