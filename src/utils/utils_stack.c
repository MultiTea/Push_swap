/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:36:13 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/06 18:21:50 by lbolea           ###   ########.fr       */
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

int	find_max(t_node **s)
{
	int		max;
	t_node	*node;

	if (!s || !*s)
		return (0);
	max = (*s)->data;
	node = (*s)->next;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	find_min(t_node **s)
{
	int		min;
	t_node	*node;

	if (!s || !*s)
		return (0);
	min = (*s)->data;
	node = (*s)->next;
	while (node)
	{
		if (node->data > min)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	stack_len(t_node **stack)
{
	t_node	*node;
	int		len;

	node = *stack;
	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

void	set_pos(t_node *stack)
{
	t_node	*node;
	int		i;
	int		size;
	int		center;

	i = 0;
	node = stack;
	size = stack_len(&stack);
	center = size / 2;
	while (node)
	{
		if (i <= center)
			node->median = true;
		else
			node->median = false;
		node->index = i;
		i++;
		node = node->next;
	}
}

t_node	*find_min_pos(t_node *stack)
{
	int		min;
	t_node	*node;
	t_node	*pos;

	if (!stack)
		return (0);
	min = stack->data;
	node = stack->next;
	pos = stack;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			pos = node;
		}
		node = node->next;
	}
	return (pos);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_len(a);
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size > 5)
		sort_large(a, b);
}
