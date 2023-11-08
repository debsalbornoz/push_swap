#include "push_swap.h"

 void  add_first(linked_list *l, int value)
 {
    if(list_is_empty(l))
    {
        node *p = create_node(value);
        l->begin = p;
        l->end = p;
        l->size++;
    }
    else {
        node *p = create_node(value);
        p->next = l->begin;
        l->begin->prev = p;
        l->begin = p;
        l->size++;
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
