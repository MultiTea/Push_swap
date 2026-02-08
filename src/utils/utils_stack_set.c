/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:19:39 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/08 01:51:39 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_pos(t_node *stack)
{
	t_node	*node;
	int		i;
	int		size;
	int		center;

	i = 0;
	node = stack;
	size = stack_len(&stack);
	center = size / 2;
	while (node)
	{
		if (i <= center)
			node->median = true;
		else
			node->median = false;
		node->index = i;
		i++;
		node = node->next;
	}
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*curr;
	t_node	*target_node;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		target_node = NULL;
		curr = b;
		while (curr)
		{
			if (a->data > curr->data && curr->data > best_index)
			{
				best_index = curr->data;
				target_node = curr;
			}
			curr = curr->next;
		}
		if (best_index == LONG_MIN)
			a->target = find_max_pos(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*curr;
	t_node	*target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		target_node = NULL;
		curr = a;
		while (curr)
		{
			if (b->data < curr->data && curr->data < best_index)
			{
				best_index = curr->data;
				target_node = curr;
			}
			curr = curr->next;
		}
		if (best_index == LONG_MAX)
			b->target = find_min_pos(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_len(&a);
	len_b = stack_len(&b);
	while (a)
	{
		cost_a = a->index;
		if (!(a->median))
			cost_a = len_a - a->index;
		cost_b = a->target->index;
		if (!(a->target->median))
			cost_b = len_b - a->target->index;
		a->cost = cost_a + cost_b;
		if (a->median == a->target->median)
		{
			if (cost_a > cost_b)
				a->cost = cost_a;
			else
				a->cost = cost_b;
		}
		a = a->next;
	}
}

void	set_price_b(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_len(&a);
	len_b = stack_len(&b);
	while (b)
	{
		cost_b = b->index;
		if (!(b->median))
			cost_b = len_b - b->index;
		cost_a = b->target->index;
		if (!(b->target->median))
			cost_a = len_a - b->target->index;
		b->cost = cost_a + cost_b;
		if (b->median == b->target->median)
		{
			if (cost_b > cost_a)
				b->cost = cost_b;
			else
				b->cost = cost_a;
		}
		b = b->next;
	}
}
