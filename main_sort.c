/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:45 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:45 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack **a, t_stack **b)
{
	push_non_lis(a, b);
	while (*b)
	{
		update_pos(*a);
		update_pos(*b);
		set_target_pos(*a, *b);
		calculate_cost(*a, *b);
		move_cheapest(a, b);
	}
	final_rotate(a);
}
