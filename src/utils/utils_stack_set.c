/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:19:39 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/07 15:23:48 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_len(t_node **stack)
{
	t_node	*node;
	int		len;

	node = *stack;
	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

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
