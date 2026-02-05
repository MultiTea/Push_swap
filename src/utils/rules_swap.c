/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 23:03:33 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !(*head) || !((*head)->next))
		exit(EXIT_FAILURE);
	first = *head;
	second = first->next;
	// INITIAL STATE
	// ft_printf("\n");
	// print_node(first);
	// print_node(second);
	// if (second->next)
	//	print_node(second->next);
	// ft_printf("\n");
	//
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	// SWAP of first next & prev
	// print_node(second);
	// print_node(first);
	// if (!first->next)
	// print_node(second->next);
	// print_node(second->next);
	// ft_printf("\n");
	//
	second->next = first;
	second->prev = NULL;
	*head = second;
	// SWAP of second next & prev
	// print_node(second);
	// print_node(first);
	// if (first->next)
	// print_node(first->next);
	// ft_printf("\n");
	//
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
