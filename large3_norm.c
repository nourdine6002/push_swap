#include "push_swap.h"

void	do_rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a, 1);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a, 1);
		(*cost_a)++;
	}
}

void	do_rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b, 1);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b, 1);
		(*cost_b)++;
	}
}
