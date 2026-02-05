/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:26 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:26 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_stack *b)
{
	int	max;

	max = -2147483648;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static void	pb_smart(t_stack **a, t_stack **b)
{
	int	max;

	pb(a, b, 1);
	if (!b || !*b || !(*b)->next)
		return ;
	max = max_index(*b);
	if ((*b)->index < max / 2)
		rb(b, 1);
}

void	best_push(t_stack **a, t_stack **b)
{
	int	limit;

	limit = stack_size(*a);
	while (stack_size(*a) > 3 && limit > 0)
	{
		pb_smart(a, b);
		limit--;
	}
	sort_3(a);
}
