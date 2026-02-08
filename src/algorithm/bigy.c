/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:12:02 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/08 01:03:49 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_len(stack_a) > 3)
	{
		set_pos(*stack_a);
		set_pos(*stack_b);
		set_target_a(*stack_a, *stack_b);
		set_price_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_pos(*stack_a);
		set_pos(*stack_b);
		set_target_b(*stack_a, *stack_b);
		set_price_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	min_to_top(stack_a);
}
