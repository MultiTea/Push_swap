/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 23:45:02 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = find_last(*stack);
	// ft_printf("\n");
	// print_node(head);
	// print_node(tail);
	//
	*stack = head->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	(*stack)->prev = NULL;
	//
	// ft_printf("\n");
	// print_node(tail);
	// print_node(head);
}
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
