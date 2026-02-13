/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:42:29 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/13 09:11:33 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	is_space(char s)
{
	if ((s >= 9 && s <= 13) || (s == 32))
		return (1);
	return (0);
}

static size_t	token_count(char const *s)
{
	size_t	token;
	size_t	i;
	int		is_word;

	token = 0;
	i = 0;
	while (s[i])
	{
		is_word = 0;
		while (is_space(s[i]) == 1 && s[i])
			i++;
		while (is_space(s[i]) == 0 && s[i])
		{
			if (is_word == 0)
				token++;
			is_word = 1;
			i++;
		}
	}
	return (token);
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

static int	add_words(char **array, char const *s)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (is_space(s[i]) == 1)
			i++;
		if (s[i])
		{
			start = i;
			while (is_space(s[i]) == 0 && s[i])
				i++;
			array[j] = ft_substr(s, start, (i - start));
			if (!array[j])
			{
				ft_free(array, j);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

char	**ft_split_args(char const *s)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = token_count(s);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!add_words(array, s))
		return (NULL);
	array[words] = NULL;
	return (array);
}
