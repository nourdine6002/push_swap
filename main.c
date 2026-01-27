/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:49 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:49 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	error_arg(ac, av);
	parsing(ac, av, &a);
	if (hendel_error(a) == 1)
		return (ft_putstr_fd("Error\n", 2), free_stack(&a), 1);
	asined_index(a);
	if (is_sorted(a))
		return (free_stack(&a), 1);
	if (stack_size(a) == 2)
		sort_2(&a);
	else if (stack_size(a) == 3)
		sort_3(&a);
	else
		sort_large(&a, &b);
	free_stack(&a);
	return (free_stack(&b), 0);
}
