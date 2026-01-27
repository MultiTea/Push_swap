/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:34:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/27 23:32:40 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	**array;

	i = 1;
	array = parsing(argc, argv);
	if (!array)
		return (1);
	while (i < argc)
	{
		printf("%s•", *array);
		i++;
		array++;
	}
	printf("\n");
	return (0);
}
