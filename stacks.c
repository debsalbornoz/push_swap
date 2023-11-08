#include "push_swap.h"

 void  add_first(linked_list *l, int value)
 {
    node *p = create_node(value);
    p->next = l->begin;
    if(list_is_empty(l))
        l->end = p;
    else
        l->begin->prev = p;
    l->begin = p;
     l->size++;

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
    if (list_is_empty(l))
        l->begin = q;
    else {
     l->end->next = q;
     q->prev = l->end;
    }
    l->end = q;
    l->size++;
 }

void create_stackb(linked_list *l, char **argv) {
    int i = 1; // Inicialize a variável i
    while (argv[i] != NULL) {
        add_last(l, atoi(argv[i]));
        i++;
    }
    print_list(l);
}
