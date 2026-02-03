/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large1_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:23 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:23 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	update_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

void	find_lis(t_stack *s)
{
	t_stack	*i;
	t_stack	*end;
	int		len;

	i = s;
	while (i)
	{
		i->in_lis = 0;
		i->lis_len = 1;
		i = i->next;
	}
	i = s;
	norm1(s);
	end = best_end(s);
	len = end->lis_len;
	while (end && len > 0)
	{
		end->in_lis = 1;
		len--;
		if (len == 0)
			break ;
		end = pred(s, end, len);
	}
}
