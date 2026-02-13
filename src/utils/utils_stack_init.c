/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:36:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/07 15:25:09 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*find_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	add_back(t_node **stack, t_node *new_node)
{
	t_node	*last_node;

	if (!new_node)
		exit(EXIT_FAILURE);
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_node **a, int *arr, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < size)
	{
		node = new_node(arr[i]);
		add_back(a, node);
		i++;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*curr;

	if (!stack | !*stack)
		exit(EXIT_FAILURE);
	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}
