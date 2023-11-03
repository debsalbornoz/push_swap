#include "push_swap.h"


int main(int argc, char **argv)
{
    linked_list *l;

    l = create_linked_list();
    if(argc ==1)
        exit(1);
    if(verify(argc, argv) == 1)
        {
            ft_printf("Error\n");
            exit(1);
        }
    create_stackb(l, argv);
    return(0);
}