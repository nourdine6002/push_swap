/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:08 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:08 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_eq(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && cmp[i] && str[i] == cmp[i])
		i++;
	if (str[i] == '\0' && cmp[i] == '\0')
		return (1);
	return (0);
}

int	apply_inst(char *s, t_stack **a, t_stack **b)
{
	if (str_eq(s, "sa\n"))
		sa(a, 0);
	else if (str_eq(s, "sb\n"))
		sb(b, 0);
	else if (str_eq(s, "ss\n"))
		ss(a, b, 0);
	else if (str_eq(s, "pa\n"))
		pa(a, b, 0);
	else if (str_eq(s, "pb\n"))
		pb(a, b, 0);
	else if (str_eq(s, "ra\n"))
		ra(a, 0);
	else if (str_eq(s, "rb\n"))
		rb(b, 0);
	else if (str_eq(s, "rr\n"))
		rr(a, b, 0);
	else if (str_eq(s, "rra\n"))
		rra(a, 0);
	else if (str_eq(s, "rrb\n"))
		rrb(b, 0);
	else if (str_eq(s, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}
