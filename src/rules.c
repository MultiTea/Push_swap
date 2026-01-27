/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/23 16:16:54 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Swap */
void	sa(t_node a);
void	sb(t_node b);
void	ss(t_node a, t_node b);
/* Push */
void	pa(t_node a, t_node b);
void	pb(t_node b, t_node a);
/* Rotate */
void	ra(t_node a);
void	rb(t_node b);
void	rr(t_node a, t_node b);
/* Reverse rotate */
void	rra(t_node a);
void	rrb(t_node b);
void	rrr(t_node a, t_node b);