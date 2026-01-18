/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:24:39 by nodoulah          #+#    #+#             */
/*   Updated: 2025/10/22 22:54:42 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str && !n)
		return (NULL);
	i = 0;
	if (!find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && find[j] && str[i + j] == find[j] && i + j < n)
			j++;
		if (!find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
