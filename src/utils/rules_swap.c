/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 14:21:49 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!head || !(*head) || !((*head)->next))
		exit(EXIT_FAILURE);
	first = *head;
	ft_printf("NODE[A] = %x (%d)\n", first, first->data);
	second = first->next;
	ft_printf("NODE[B] = %x (%d)\n", second, second->data);
	third = second->next;
	ft_printf("NODE[C] = %x (%d)\n", third, third->data);
	first->next = second->next;
	ft_printf("NODE[A (%x - %d)] -> NODE[C](%x - %d)\n", first, first->data,
		first->next, first->next->data);
	first->prev = second;
	ft_printf("NODE[B (%x - %d)] <- NODE[A](%x - %d)\n", first->prev,
		first->prev->data, first, first->data);
	//
	ft_printf("\n");
	ft_printf("NODE[B] <- NODE[A] -> NODE[C]\n");
	ft_printf("%d <- %d -> %d\n", first->prev->data, first->data,
		first->next->data);
	ft_printf("%d <- %d -> %d\n", second->prev->data, second->data,
		second->next->data);
	ft_printf("\n");
	//
	second->next = first;
	second->prev = NULL;
	*head = second;
}
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node b);