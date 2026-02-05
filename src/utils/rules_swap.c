/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 17:04:01 by lbolea           ###   ########.fr       */
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
	// ft_printf("\n%d <- %d -> %d", first->prev, first->data,
	// first->next->data);
	// ft_printf("\n");
	// ft_printf("%d <- %d -> %d\n", second->prev->data, second->data,
	// second->next->data);
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*head = second;
	// ft_printf("\n");
	// ft_printf("%d <- %d -> %d\n", first->prev->data, first->data,
	// 	first->next->data);
	// ft_printf("%d <- %d -> %d\n", second->prev, second->data,
	// 	second->next->data);
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
