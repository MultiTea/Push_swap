/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:19:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 17:00:51 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include "../libs/printf/include/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
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
int					is_dup(int argc, char **argv);

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
// Structure management
t_node				*new_node(int content);
t_node				*find_last(t_node *head);
void				add_back(t_node **stack, t_node *new_node);
void				init_stack_a(t_node **a, int *arr, int size);
void				print_list(t_node *stack);
void				free_stack(t_node **stack);

/// ――― OPERATIONS ――― ///
// rules_swap
void				swap(t_node **head);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
// rules_push
void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);
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
#endif