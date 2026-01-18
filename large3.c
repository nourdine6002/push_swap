/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:42 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:42 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	total_cost(int a, int b)
{
	int	aa;
	int	ab;

	aa = to_abs(a);
	ab = to_abs(b);
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return (max_int(aa, ab));
	return (aa + ab);
}

static t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*best;
	int		best_cost;
	int		cost;

	if (!b)
		return (NULL);
	best = b;
	best_cost = total_cost(b->cost_a, b->cost_b);
	b = b->next;
	while (b)
	{
		cost = total_cost(b->cost_a, b->cost_b);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = b;
		}
		b = b->next;
	}
	return (best);
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheap;
	int		cost_a;
	int		cost_b;

	if (!b || !*b)
		return ;
	cheap = get_cheapest(*b);
	if (!cheap)
		return ;
	cost_a = cheap->cost_a;
	cost_b = cheap->cost_b;
	do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	pa(a, b, 1);
}
