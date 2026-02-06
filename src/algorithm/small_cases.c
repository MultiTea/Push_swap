/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:48:59 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/06 17:47:44 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_node **a)
{
	int	head;
	int	mid;
	int	max;

	head = (*a)->data;
	mid = (*a)->next->data;
	max = find_max(a);
	if (head == max)
		ra(a);
	else if (mid == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;
	int		i;

	i = 2;
	while (i--)
	{
		set_pos(*stack_a);
		min = find_min_pos(*stack_a);
		while (*stack_a != min)
		{
			if (min->median)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
