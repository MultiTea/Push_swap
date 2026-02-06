/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:34:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/06 17:44:46 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*array;
	int		size;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	array = parsing(argc, argv, &size);
	if (!array)
		return (1);
	init_stack_a(&stack_a, array, size);
	//// --------------------------------
	print_lists(stack_a, stack_b);
	ft_printf("\n");
	//// --------------------------------
	sort_five(&stack_a, &stack_b);
	//// --------------------------------
	print_lists(stack_a, stack_b);
	//// --------------------------------
	free(array);
	free_stack(&stack_a);
	return (0);
}
