/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:16:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/08 01:51:34 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = set_cheapest(*a);
	if (cheapest->median && cheapest->target->median)
	{
		while ((*a != cheapest) && (*b != cheapest->target))
			rr(a, b);
	}
	else if (!cheapest->median && !cheapest->target->median)
	{
		while ((*a != cheapest) && (*b != cheapest->target))
			rrr(a, b);
	}
	rotate_to_head(a, cheapest, 'a');
	rotate_to_head(b, cheapest->target, 'b');
	pb(a, b);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = set_cheapest(*b);
	if (cheapest->median && cheapest->target->median)
	{
		while ((*b != cheapest) && (*a != cheapest->target))
			rr(a, b);
	}
	else if (!cheapest->median && !cheapest->target->median)
	{
		while ((*b != cheapest) && (*a != cheapest->target))
			rrr(a, b);
	}
	rotate_to_head(b, cheapest, 'b');
	rotate_to_head(a, cheapest->target, 'a');
	pa(a, b);
}

void	rotate_to_head(t_node **stack, t_node *node, char s_name)
{
	while (*stack != node)
	{
		if (s_name == 'a')
		{
			if (node->median)
				ra(stack);
			if (!node->median)
				rra(stack);
		}
		if (s_name == 'b')
		{
			if (node->median)
				rb(stack);
			if (!node->median)
				rrb(stack);
		}
	}
}

void	min_to_top(t_node **a)
{
	t_node	*node;

	set_pos(*a);
	node = find_min_pos(*a);
	rotate_to_head(a, node, 'a');
}

t_node	*set_cheapest(t_node *stack)
{
	t_node	*node;
	int		cost;

	if (!stack)
		return (NULL);
	node = stack;
	cost = stack->cost;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
	return (node);
}
