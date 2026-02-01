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

void	free_max_min(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
