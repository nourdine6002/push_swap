/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:24:57 by nodoulah          #+#    #+#             */
/*   Updated: 2025/10/25 21:26:04 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found_start(const char *str, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (str[i] != set[j])
			return (i);
		i++;
	}
	return (i);
}

static int	found_end(const char *str, const char *set)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (str[i] != set[j])
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = found_start(s1, set);
	end = found_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	res = malloc((end - start + 1) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
