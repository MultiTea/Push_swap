/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:34:00 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/15 17:58:53 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 1)
		return (1);
	if (argc >= 2)
	{
		i = 2;
		if (!argv)
			return (1);
		while (i < argc)
			**ft_split(argv[i], " ");
	}
	return (0);
}
