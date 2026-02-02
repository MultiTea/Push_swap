/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:15:43 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/02 20:27:14 by lbolea           ###   ########.fr       */
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
		if (is_empty(argv[i]) == 1)
			return (1);
		while (j < arg_len)
		{
			if ((argv[i][j] == '-' || (argv[i][j] >= 9 && argv[i][j] <= 13)
					|| argv[i][j] == 32))
				j++;
			else if (argv[i][j] == '\0')
				break ;
			else if (!(ft_isdigit(argv[i][j])))
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

char	*stringify(int argc, char **argv, char *str)
{
	char	*tmp;
	char	*add_delimiter;
	int		i;

	i = 1;
	while (i < argc)
	{
		tmp = str;
		if (!tmp)
		{
			tmp = NULL;
			return (NULL);
		}
		add_delimiter = ft_strjoin(tmp, " ");
		if (!add_delimiter)
			return (NULL);
		str = ft_strjoin(add_delimiter, argv[i]);
		free(add_delimiter);
		free(tmp);
		i++;
	}
	return (str);
}

int	*atoify(char **args, int *arr)
{
	int		i;
	long	nb;

	i = 0;
	while (args[i])
	{
		nb = ft_atol(args[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (ft_error());
		arr[i] = ft_atoi(args[i]);
		i++;
	}
	return (arr);
}

int	*parsing(int argc, char **argv, int *len)
{
	char	**args;
	char	*str;
	int		*arr;
	int		i;

	if (argc <= 1 || is_digit(argv) == 1 || is_dup(argc, argv) == 1)
		return (ft_error());
	else
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
		str = stringify(argc, argv, str);
		args = ft_split_args(str);
		free(str);
		i = 0;
		while (args[i])
			i++;
		*len = i;
		arr = malloc(sizeof(int) * i);
		arr = atoify(args, arr);
		free_arr(args, i);
		return (arr);
	}
}
