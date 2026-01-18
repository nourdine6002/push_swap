/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:24:48 by nodoulah          #+#    #+#             */
/*   Updated: 2025/10/21 22:08:50 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				len;
	unsigned char	*p;

	len = ft_strlen(s);
	p = (unsigned char *)s;
	i = len;
	while (i >= 0)
	{
		if (p[i] == (unsigned char)c)
			return ((char *)&p[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&p[i]);
	return (NULL);
}
