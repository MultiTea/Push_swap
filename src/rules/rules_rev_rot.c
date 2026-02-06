/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/06 12:17:26 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;
	t_node	*bef_last;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	tail = find_last(*stack);
	bef_last = tail->prev;
	////
	// ft_printf("\n");
	// print_node(head);
	// print_node(second);
	// print_node(bef_last);
	// print_node(tail);
	////
	tail->prev->next = NULL;
	tail->next = head;
	head->prev = tail;
	tail->prev = NULL;
	*stack = tail;
	////
	// ft_printf("\n");
	// print_node(tail);
	// print_node(head);
	// print_node(second);
	// print_node(bef_last);
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
