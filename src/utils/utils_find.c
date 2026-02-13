/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:20:57 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/07 15:23:19 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_min(t_node **s)
{
	int		min;
	t_node	*node;

	if (!s || !*s)
		return (0);
	min = (*s)->data;
	node = (*s)->next;
	while (node)
	{
		if (node->data > min)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	find_max(t_node **s)
{
	int		max;
	t_node	*node;

	if (!s || !*s)
		return (0);
	max = (*s)->data;
	node = (*s)->next;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

t_node	*find_min_pos(t_node *stack)
{
	int		min;
	t_node	*node;
	t_node	*pos;

	if (!stack)
		return (0);
	min = stack->data;
	node = stack->next;
	pos = stack;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			pos = node;
		}
		node = node->next;
	}
	return (pos);
}

t_node	*find_max_pos(t_node *stack)
{
	int		max;
	t_node	*node;
	t_node	*pos;

	if (!stack)
		return (0);
	max = stack->data;
	node = stack->next;
	pos = stack;
	while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			pos = node;
		}
		node = node->next;
	}
	return (pos);
}
