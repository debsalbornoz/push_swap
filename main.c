#include "push_swap.h"

int main(int argc, char **argv)
{
    if(argc ==1)
        exit(1);
    if(verify(argc, argv) == 1)
        {
            ft_printf("Error\n");
            exit(1);
        }
}