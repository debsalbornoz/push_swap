/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/08 21:28:54 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"

# define MAX_INTEIRO 2147483647
# define MIN_INTEIRO -2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_linked_list
{
	t_node			*begin;
	t_node			*end;
	size_t			size;
}					t_linked_list;

int					arguments_number(int argc);
int					is_number(char *s);
int					verify(int argc, char **argv);
int					duplicates(char **argv);
int					max_int(char **argv);
long				ft_custom_atoi(const char *nptr);
t_linked_list		*create_linked_list(void);
t_node				*create_node(int value);
void				add_first(t_linked_list *l, int value);
void				print_list(t_linked_list *l);
void				create_stacka(t_linked_list *l, char **argv);
void				add_last(t_linked_list *l, int value);
void				create_stackb(t_linked_list *l, char **argv);
void				destroy_linked_list(t_linked_list **l_ref);
int					list_is_empty(const t_linked_list *l);

#endif