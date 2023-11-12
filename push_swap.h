/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/11 19:41:01 by dlamark-         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node			*begin;
	t_node			*end;
	size_t			size;
}					t_stack;
// Verifications
int					arguments_number(int argc);
int					is_number(char *s);
int					verify(char **argv);
int					duplicates(char **argv);
int					max_int(char **argv);
long				ft_custom_atoi(const char *nptr);

// Operations

void				swap(t_stack *l);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack *src, t_stack *dest);
void				rotate(t_stack *src);
void				rr(t_stack *a, t_stack *b);

// Stacks
t_stack	*create_stack(void);
t_node	*create_node(int value);
void	add_node(t_stack *stack, int value);
void	initialize_stack(t_stack *a, char **argv);
void destroy_stack(t_stack **stack_ref);
void	print_list(t_stack *l);

#endif