/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large2_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:30 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:30 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_splite(char **spliter)
{
	int	j;

	j = 0;
	ft_putstr_fd("Error\n", 2);
	while (spliter[j])
		free(spliter[j++]);
	free(spliter);
	exit(1);
}

void	norm1(t_stack *s)
{
	t_stack	*i;
	t_stack	*j;

	i = s;
	while (i)
	{
		j = s;
		while (j != i)
		{
			if (j->index < i->index && j->lis_len + 1 > i->lis_len)
				i->lis_len = j->lis_len + 1;
			j = j->next;
		}
		i = i->next;
	}
}

void	free_max_min(char **spliter)
{
	int	j;
	int	error;

	j = 0;
	while (spliter[j])
	{
		error = 0;
		ft_atoi2(spliter[j], &error);
		if (error == 1)
			free_splite(spliter);
		j++;
	}
}
