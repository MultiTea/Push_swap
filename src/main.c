/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:34:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/05 13:02:49 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*array;
	int		size;
	t_node	*stack_a;

	stack_a = NULL;
	size = 0;
	array = parsing(argc, argv, &size);
	if (!array)
		return (1);
	init_stack_a(&stack_a, array, size);
	swap(&stack_a);
	print_list(stack_a);
	free(array);
	free_stack(&stack_a);
	return (0);
}
