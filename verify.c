#include "push_swap.h"

int arguments(int argc);
int is_number(char *s);
int duplicates(char **argv);
int max_int(char **argv);

int verify(int argc, char **argv)
{
    int i;
    i = 1; 
    if(arguments(argc) == 1)
        return(1);
    while(argv[i] != NULL)
    {
        if(is_number(argv[i]) == 1 )
            return(1);    
        i++;
    }
    if(duplicates(argv) == 1 || max_int(argv) == 1)
        return(1);
    return(0);
}

int arguments(int argc)
{
    if(argc == 2)
    {
        ft_printf("The program expects more than one argument to sort the stack\n");
        return(1);
    }
    return(0);
}

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


int duplicates(char **argv)
{
    int i;
    int j;

    i = 1;
    j = i + 1;
    while(argv[i] != NULL)
    {
        if(argv[j] == NULL)
            break;
        while(argv[j] != NULL)
        {
            if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
                {
                    ft_printf("Arguments duplicated\n");
                    return(1);
                }
            j++;
        }
        if(argv[j] == NULL)
        {
            i++;
            j = i +1;
        }

    }
    return(0);
}

int max_int(char **argv)
{
    int i;

    i = 1;
    while(argv[i] != NULL)
    {
        if( ft_atoi(argv[i]) >= __INT_MAX__)
        {
            ft_printf("Argument equal or greater than an int\n");
            return(1);
        }
        i++;
    }
    return(0);
}