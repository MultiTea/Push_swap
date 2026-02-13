/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:19:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/09 21:57:15 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include "../libs/printf/include/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

/// ――― INPUT HANDLING ――― ///
// Parsing

int					*parsing(int argc, char *argv[], int *len);
char				**ft_split_args(char const *s);

// Utils
/*General*/

void				free_arr(char **array, size_t position);
long				ft_atol(const char *nptr);

/*Parsing*/

int					ft_check(int argc, char **argv);
int					ft_check_str(char *argv);
int					is_empty(char *str);
int					is_dup(int argc, char **argv, int start_at);
int					is_syntax_valid(char *arg);

/// ――― ERROR HANDLING ――― ///

void				*ft_error(void);

/// ――― STACK MANAGEMENT ――― ///
// Structure

typedef struct s_node
{
	int				data;
	int				index;

	int				cost;
	bool			median;
	bool			cheapest;

	struct s_node	*target;

	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Stack management

t_node				*new_node(int content);
void				add_back(t_node **stack, t_node *new_node);
void				init_stack_a(t_node **a, int *arr, int size);
void				free_stack(t_node **stack);

// Stack set

int					stack_len(t_node **stack);
void				set_pos(t_node *stack);
t_node				*set_cheapest(t_node *stack);
void				set_target_a(t_node *a, t_node *b);
void				set_target_b(t_node *a, t_node *b);
void				set_price_a(t_node *a, t_node *b);
void				set_price_b(t_node *a, t_node *b);

// Debug tools

void				print_list(t_node *stack);
void				print_lists(t_node *a, t_node *b);
void				print_node(t_node *node);

// Find number/node

int					find_max(t_node **s);
int					find_min(t_node **s);
t_node				*find_min_pos(t_node *stack);
t_node				*find_max_pos(t_node *stack);
t_node				*find_last(t_node *head);

// Stack sorting

void				sort_stack(t_node **a, t_node **b);
void				move_a_to_b(t_node **a, t_node **b);
void				move_b_to_a(t_node **a, t_node **b);
void				rotate_to_head(t_node **stack, t_node *node, char s_name);
void				min_to_top(t_node **a);

/// ――― OPERATIONS ――― ///
// rules_swap

void				swap(t_node **head);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

// rules_push
void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

// rules_rotate
void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

// rules_rev_rot
void				rev_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

/// ――― ALGORITHM ――― ///

void				sort_three(t_node **s);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				sort_big(t_node **stack_a, t_node **stack_b);
#endif