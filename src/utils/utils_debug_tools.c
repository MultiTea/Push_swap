/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:24:22 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/07 15:26:04 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
