/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:34:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/31 23:15:56 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int	*array;
	int	i;
	int	size;

	size = 0;
	array = parsing(argc, argv, &size);
	if (!array)
		return (1);
	i = 0;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}
