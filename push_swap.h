/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/15 14:40:27 by dlamark-         ###   ########.fr       */
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
int					check_args(char **argv);
int					duplicates(char **argv);
int					max_int(char **argv);
long				ft_custom_atoi(const char *nptr);

// Operations

void				swap(t_stack *stack, char stack_name);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack *src, t_stack *dest, char stack_name);
void				rotate(t_stack *stack, char stack_name);
void				rr(t_stack *a, t_stack *b);
void				reverse_rotate(t_stack *stack, char stack_name);

// Stacks
t_stack				*create_stack(void);
t_node				*create_node(int value);
void				add_node(t_stack *stack, int value);
void				initialize_stack(t_stack *a, char **argv);
void				destroy_stack(t_stack **stack_ref);
void				print_list(t_stack *l);

//Algoritm
void				push_swap(t_stack *a, t_stack *b);
void				handle_two_elements(t_stack *stack);
int 				find_target_node(t_stack *a, t_stack *b);
#endif