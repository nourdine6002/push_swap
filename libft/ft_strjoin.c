/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:30 by nodoulah          #+#    #+#             */
/*   Updated: 2025/10/26 03:14:22 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcopy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*strj;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	strj = malloc((l1 + l2 + 1) * sizeof(char));
	if (!strj)
		return (NULL);
	ft_strcopy(strj, s1, l1);
	strj[l1] = ' ';
	ft_strcopy(strj + l1 + 1, s2, l2);
	strj[l1 + l2 + 1] = '\0';
	return (strj);
}
