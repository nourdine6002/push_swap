/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:51:55 by nodoulah          #+#    #+#             */
/*   Updated: 2026/02/03 10:55:54 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asined_index(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*cmp;
	int		index;

	tmp1 = stack;
	while (tmp1)
	{
		index = 0;
		cmp = stack;
		while (cmp)
		{
			if (tmp1->val > cmp->val)
				index++;
			cmp = cmp->next;
		}
		tmp1->index = index;
		tmp1 = tmp1->next;
	}
}

void	free_max_min(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	non_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
