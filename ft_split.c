/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:08 by nodoulah          #+#    #+#             */
/*   Updated: 2026/02/03 10:40:24 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	*get_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	end;
	size_t	j;
	char	*word;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	end = *i;
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (start < end)
		word[j++] = s[start++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	count;
	char	**res;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (index < count)
	{
		res[index] = get_word(s, c, &i);
		if (!res[index])
			return (free_split(res, index), NULL);
		index++;
	}
	res[index] = NULL;
	return (res);
}
