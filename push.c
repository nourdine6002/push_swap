/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:59 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:59 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack, t_stack **empty)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	tmp->next = *empty;
	*empty = tmp;
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print == 1)
		ft_putstr_fd("pb\n", 1);
}
