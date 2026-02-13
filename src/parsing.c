/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:15:43 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/13 09:33:14 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_args(char **args)
{
	int	i;

	if (!*args && !args)
		return (0);
	i = 0;
	while (args[i])
		i++;
	return (i);
}

static char	*stringify(int argc, char **argv, char *str)
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

static int	*atoify(char **args, int *arr, int len)
{
	int	i;

	i = 0;
	while (args[i])
	{
		arr[i] = ft_atoi(args[i]);
		i++;
	}
	if (is_dup(i, args, 0) == 1)
	{
		free(arr);
		free_arr(args, len);
		return (ft_error());
	}
	return (arr);
}

static int	*parse_args(int argc, char **argv, int *len)
{
	char	**args;
	char	*str;
	int		*arr;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	str = stringify(argc, argv, str);
	args = ft_split_args(str);
	if (!args)
		return (0);
	free(str);
	*len = count_args(args);
	arr = malloc(sizeof(int) * (*len));
	if (!arr)
		return (0);
	arr = atoify(args, arr, *len);
	free_arr(args, *len);
	return (arr);
}

int	*parsing(int argc, char **argv, int *len)
{
	if (ft_check(argc, argv) == 2)
		return (0);
	else if (ft_check(argc, argv) == 1)
		return (ft_error());
	else
		return (parse_args(argc, argv, len));
}
