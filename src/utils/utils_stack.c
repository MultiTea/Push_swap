/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:36:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 22:53:21 by lbolea           ###   ########.fr       */
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

void	print_list(t_node *stack)
{
	ft_printf("\n");
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
	ft_printf("―\na\n");
}

void	print_lists(t_node *a, t_node *b)
{
	ft_printf("\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d   ", a->data);
			a = a->next;
		}
		else
			ft_printf("    ");
		if (b)
		{
			ft_printf("%d", b->data);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("―   ―\n");
	ft_printf("a   b\n");
}

void	print_node(t_node *node)
{
	int		n_data;
	t_node	*n_prev;
	t_node	*n_next;

	if (!node)
		return ;
	n_data = node->data;
	n_prev = node->prev;
	n_next = node->next;
	ft_printf("@(%X) = %d - Prev: %x - Next: %x\n", node, n_data, n_prev,
		n_next);
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
