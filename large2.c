#include "push_swap.h"

static int	min_index_pos(t_stack *a)
{
	int	min_index;
	int	min_pos;

	min_index = 2147483647;
	min_pos = 0;
	while (a)
	{
		if (a->index < min_index)
		{
			min_index = a->index;
			min_pos = a->pos;
		}
		a = a->next;
	}
	return (min_pos);
}

void	set_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*ta;
	int		best_index;
	int		target;

	while (b)
	{
		best_index = 2147483647;
		target = 0;
		ta = a;
		while (ta)
		{
			if (ta->index > b->index && ta->index < best_index)
			{
				best_index = ta->index;
				target = ta->pos;
			}
			ta = ta->next;
		}
		if (best_index == 2147483647)
			b->target_pos = min_index_pos(a);
		else
			b->target_pos = target;
		b = b->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->pos <= size_b / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = b->pos - size_b;
		if (b->target_pos <= size_a / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = b->target_pos - size_a;
		b = b->next;
	}
}

int	to_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	final_rotate(t_stack **a)
{
	int	pos_min;
	int	size;

	if (!a || !*a)
		return ;
	update_pos(*a);
	size = stack_size(*a);
	pos_min = min_index_pos(*a);
	if (pos_min <= size / 2)
	{
		while (pos_min > 0)
		{
			ra(a, 1);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < size)
		{
			rra(a, 1);
			pos_min++;
		}
	}
}
