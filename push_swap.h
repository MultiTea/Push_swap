/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:19:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/15 18:01:19 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

// ――― INPUT HANDLING ――― //
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char const *s, char c);
int					ft_atol(const char *nptr);

// ――― ERROR HANDLING ――― //

// ――― STACK MANAGEMENT ――― //

/* Structure */
typedef struct s_node
{
	int				data;
	int				index;

	int				cost;
	bool			median;
	bool			cheapest;

	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

t_node				stack_init(unsigned int capacity);
int					isEmpty(t_node stack);

// ――― OPERATIONS ――― //
/* Swap */
void				sa(t_node a);
void				sb(t_node b);
void				ss(t_node a, t_node b);
/* Push */
void				pa(t_node a, t_node b);
void				pb(t_node b, t_node a);
/* Rotate */
void				ra(t_node a);
void				rb(t_node b);
void				rr(t_node a, t_node b);
/* Reverse rotate */
void				rra(t_node a);
void				rrb(t_node b);
void				rrr(t_node a, t_node b);

// ――― ALGORITHM ――― //

#endif
