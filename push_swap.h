/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/10/31 21:05:03 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H 

#include "libft/libft.h"
#include <limits.h>

typedef struct node{
    int value;
    struct node *prev;
    struct  node *next;
} node;

typedef struct linked_list{

    node *begin;
    node *end;
    size_t  size;
} linked_list;

int arguments_number(int argc);
int is_number(char *s);
int verify(int argc, char **argv);
int duplicates(char **argv);
int max_int(char **argv);
long long ft_custom_atoi(const char *nptr);
linked_list *create_linked_list();
node    *create_node(int value);
void  add_first(linked_list *l, int value);
 void print_list(linked_list *l);
void    create_stacka(linked_list *l, char **argv);
 void  add_last(linked_list *l, int value);
void    create_stackb(linked_list *l, char **argv);
void destroy_linked_list(linked_list **l_ref);
int list_is_empty(const linked_list *l);

#endif