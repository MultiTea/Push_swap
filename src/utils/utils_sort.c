/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:17:40 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/07 15:26:18 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
		sort_bigy(a, b);
}
