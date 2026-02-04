/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:53:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/04 21:48:27 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (head || !*head || !((*head)->next))
		exit(EXIT_FAILURE);
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = NULL;
	second->prev = NULL;
}
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node b);