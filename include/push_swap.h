/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:19:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/27 15:01:09 by lbolea           ###   ########.fr       */
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

// ――― INPUT HANDLING ――― //
/* Parsing */
char				**parsing(int argc, char *argv[]);
/* Libft */
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
/* Utils */

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

	struct s_node	*head;
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
void				rra(t_node a);
void				rrb(t_node b);
void				rrr(t_node a, t_node b);

// ――― ALGORITHM ――― //

#endif
