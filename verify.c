#include "push_swap.h"

int is_number(char *s)
{
    int i;
    
    i = 0;
    while(s[i] != '\0')
    {
        if(ft_isdigit(s[i]) == 0)
        {
            ft_printf("The arguments should be only digits\n");
            return(1);
        }
        i++;      
    }
    return(0);
}

int arguments(int argc)
{
    if(argc == 2)
    {
        ft_printf("The program expects more than one argument to sort the stack\n")
        return(1);
    }
    return(0);
}
int check_duplicates(char **argv)
{
    int i;
    i = 0;
    while(argv[i] != NULL)
    {
        if(argv[i + 1] == NULL)
            break;

        i++;
    }
}

int verify(int argc, char **argv)
{
    int i;
    i = 1;
    if
    while(argv[i] != NULL)
    {
        if(arguments(argc) == 1)
            return(1);
        if(is_number(argv[i]) == 1 )
            return(1);
        i++;
    }
    return(0);
}