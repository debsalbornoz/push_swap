#include "push_swap.h"

linked_list *create_linked_list()
{
    linked_list *l = (linked_list    *)ft_calloc(1, sizeof(linked_list));
    l->begin = NULL;
    l->end = NULL;
    return(l);
}

node    *create_node(int value){

    node    *snode = (node  *)ft_calloc(1, sizeof(node));
    snode->value = value;
    snode->next = NULL;
    return(snode);
}

 void  add_first(linked_list *l, int value)
 {
    node    *p;

    p = create_node(value);
    p->next= l->begin;
    l->begin = p;

    if(l->begin == NULL && l->end == NULL)
    {
        l->end = p;
    }


 }

 void print_list(linked_list *l)
 {
    node *p = l->begin;
    while(p != NULL)
    {
        ft_printf("%i\n",p->value);
        p = p->next;
    }
 }

 void create_stacka(linked_list *l, char **argv)
 {
    int i;;
    i = 1;
    while (argv[i] != NULL) {
        add_first(l, atoi(argv[i]));
        i++;
    }

    print_list(l);
 }

 void add_last(linked_list *l, int value) {
    
    node    *q = create_node(value);
    if (l->begin == NULL) {
      l->begin = q;
      l->end = q;
    } else {
     l->end->next = q;
     l->end = l->end->next;
    }
 }

void create_stackb(linked_list *l, char **argv) {
    int i = 1; // Inicialize a variável i
    while (argv[i] != NULL) {
        add_last(l, atoi(argv[i]));
        i++;
    }
    print_list(l);
}
