/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:04:47 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/31 23:12:38 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_free(char **array, size_t position)
{
	size_t	i;

	i = 0;
	while (i < position)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	*ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (NULL);
}
