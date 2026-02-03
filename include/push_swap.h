/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:19:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/03 16:34:38 by lbolea           ###   ########.fr       */
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
int					*parsing(int argc, char *argv[], int *len);
char				**ft_split_args(char const *s);
/* Libft */
char				*ft_strjoin(char const *s1, char const *s2);
/* Utils */
// General
void				free_arr(char **array, size_t position);

long				ft_atol(const char *nptr);
//	Parsing
int					ft_check(int argc, char **argv);
int					ft_check_str(char *argv);
int					is_empty(char *str);
int					is_dup(int argc, char **argv);

// ――― ERROR HANDLING ――― //
/* General */
void				*ft_error(void);
/* Libft */
void				ft_putendl_fd(char *s, int fd);

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
