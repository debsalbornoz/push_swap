#include "push_swap.h"

linked_list *create_linked_list()
{
    linked_list *l = (linked_list    *)ft_calloc(1, sizeof(linked_list));
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;
    return(l);
}

node    *create_node(int value){

    node    *snode = (node  *)ft_calloc(1, sizeof(snode));
    snode->prev = NULL;
    snode->next = NULL;
    snode->value = value;
    
    return(snode);
}

void destroy_linked_list(linked_list **l_ref)
{
    linked_list *l = *l_ref;
    node *p = l->begin;
    node *aux = NULL;
    while(p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    *l_ref= NULL;
}

int list_is_empty(const linked_list *l)
{
    if((l->size == 0) && (l->begin == NULL) && (l->end == NULL))
        return(1);
    else
        return(0);

}

void    remove_node(linked_list  *l, int value)
{
    if(!list_is_empty(l))
    {
        if(l->begin->value == value)
        {
            node *p = l->begin;
            l->begin = p->next;
            if(l->end == p)
                l->end = NULL;
            else
                l->begin->prev = NULL;
            free(p);
            l->size--;
        }
        else
        {
            node *p = l->begin->next;
            while(p != NULL)
            {
                if(p->value == value)
                {
                    if(l->end == p )
                    {
                        l->end = p->prev;
                        l->end->next = NULL;
                    }
                    else {
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }
                }
                free(p);
                p = NULL;
                l->size--;
                else
                    p = p->next;
            }
        }
    }
}