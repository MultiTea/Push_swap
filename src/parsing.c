/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:15:43 by lbolea            #+#    #+#             */
/*   Updated: 2026/01/28 00:40:18 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//	1. Append arguments from main()
//		--> Join all arguments in a single string (ft_strjoin)

//	2. Convert to integer
//		--> Clean up all entries from separators (ft_split)
//		--> Convert to integers (ft_atoi)

//	3. Verify the entries for errors
// 		--> if not integer (ft_isdigit) or exceed limits (INT_MIN & INT_MAX)
//		--> if duplicates, return error

//	4. Return an array of integers

static int	is_digit(char **argv)
{
	int		i;
	size_t	j;
	size_t	arg_len;

	i = 1;
	while (argv[i] != NULL)
	{
		arg_len = ft_strlen(argv[i]);
		j = 0;
		while (j < arg_len)
		{
			if (argv[i][j] == '-' || argv[i][j] == ' ')
				j++;
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!(ft_strncmp(argv[i], argv[j], 11)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_free(char **array, size_t position)
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

static char	**join_args(int argc, char **argv, char **arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		arr[j] = ft_strjoin(argv[i], " ");
		if (!arr[j])
		{
			ft_free(arr, j);
			return (NULL);
		}
		i++;
		j++;
	}
	arr[argc] = NULL;
	return (arr);
}

char	**parsing(int argc, char **argv)
{
	char	**arr;
	char	**args;
	int		i;

	if (argc <= 1 || is_digit(argv) == 1 || is_dup(argc, argv) == 1)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	else
	{
		arr = malloc(sizeof(char *) * argc);
		if (!arr)
			return (NULL);
		arr = join_args(argc, argv, arr);
		args = ft_split(*arr, ' ');
		i = 0;
		while (args[i] != NULL)
		{
			printf("%s→", args[i]);
			i++;
		}
		printf("\n");
		return (arr);
	}
}
