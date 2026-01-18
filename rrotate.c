/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:10:05 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:10:05 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, int print)
{
	rrotate(a);
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int print)
{
	rrotate(b);
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rrotate(a);
	rrotate(b);
	if (print == 1)
		ft_putstr_fd("rrr\n", 1);
}
