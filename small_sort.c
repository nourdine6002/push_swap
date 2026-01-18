/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:10:10 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:10:10 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a, 1);
}

void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->val;
	y = (*a)->next->val;
	z = (*a)->next->next->val;
	if (x > y && y < z && x < z)
		sa(a, 1);
	else if (x > y && y > z)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		rra(a, 1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	sort_3(a);
	pa(a, b, 1);
	sort_2(a);
	pb(a, b, 1);
	pb(a, b, 1);
}
