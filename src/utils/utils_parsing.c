/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:59:05 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/03 17:19:21 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_digit(char **argv)
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
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;
	int	nb;

	if (argc <= 1 || is_digit(argv) == 1 || is_dup(argc, argv) == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (1);
		if (ft_strlen(argv[i]) >= 10)
			if (ft_check_str(argv[i]) == 1)
				return (1);
		i++;
	}
	return (0);
}

int	ft_check_str(char *argv)
{
	int		j;
	int		k;
	char	**str;
	long	nb;

	str = ft_split(argv, ' ');
	k = 0;
	while (str[k])
		k++;
	j = 0;
	while (str[j])
	{
		nb = ft_atol(str[j]);
		if (nb < INT_MIN || nb > INT_MAX || ft_strlen(str[j]) > 11)
		{
			free_arr(str, k);
			return (1);
		}
		j++;
	}
	free_arr(str, k);
	return (0);
}

int	is_empty(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (str[i] == 32)
		i++;
	if (i == j)
		return (1);
	return (0);
}

int	is_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
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
