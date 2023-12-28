/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:04:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/11/22 20:22:24 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

# define MAX_INTEGER 2147483647
# define MIN_INTEGER -2147483648
# define MAX_LONG 9223372036854775807

typedef struct s_node
{
	int				value;
	int				push_price;
	int				current_position;
	bool			cheapest;
	bool			above_median;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target_node;
}					t_node;

typedef struct s_stack
{
	t_node			*begin;
	t_node			*end;
	size_t			size;
}					t_stack;

//Check arguments

int					check_args(char **argv);
int					is_number(char *s);
int					check_duplicates(char **argv);
int					check_max_int(char **argv);
long				ft_custom_atoi(const char *nptr);

// Create stacks
t_stack				*create_stack(void);
t_node				*create_node(int value);
void				add_node(t_stack *stack, int value);
void				create_stack_a(t_stack **a, t_stack **b, char **argv);
void				print_list(t_stack *l);

//Initializate stacks

void				initialize_stacks(t_stack **a, t_stack **b);
void				initialize_positions(t_stack *stack);
void				define_target_node(t_stack *a, t_stack *b);
void				calculate_push_price(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *b);
void				get_relative_positions(t_stack *stack);
t_node 				*find_cheapest(t_stack *stack);

// Operations

void				swap(t_stack **stack, char stack_name);
void				ss(t_stack **a, t_stack **b);
void				push(t_stack **src, t_stack **dest, char stack_name);
void				rotate(t_stack **stack, char stack_name);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack, char stack_name);
void				rrr(t_stack **a, t_stack **b);

//Algorithm

void				tiny_sort(t_stack **a);
void				push_swap(t_stack **a, t_stack **b);
int					stack_sorted(t_stack *a);
t_node				*find_min_value(t_stack *node);
t_node				*find_max_value(t_stack *node);
void				current_position(t_stack *stack);
void				rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node);
void				move_nodes(t_stack **a, t_stack **b);
void				reverse_rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node);
void				finish_rotation(t_stack **stack, t_node *top_node, char stack_name);

//Free stacks
void				free_stack(t_stack **stack_ref);
void				free_stacks(t_stack **a, t_stack **b);

#endif