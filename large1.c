#include "push_swap.h"

t_stack	*best_end(t_stack *s)
{
	t_stack	*best;

	best = s;
	while (s)
	{
		if (s->lis_len > best->lis_len)
			best = s;
		s = s->next;
	}
	return (best);
}

t_stack	*pred(t_stack *head, t_stack *end, int need)
{
	t_stack	*t;
	t_stack	*best;

	t = head;
	best = NULL;
	while (t && t != end)
	{
		if (t->lis_len == need && t->index < end->index)
		{
			if (!best || t->index > best->index)
				best = t;
		}
		t = t->next;
	}
	return (best);
}

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

void	push_non_lis(t_stack **a, t_stack **b)
{
	int	limit;

	find_lis(*a);
	limit = stack_size(*a);
	while (stack_size(*a) > 3 && limit > 0)
	{
		if ((*a)->in_lis == 1)
			ra(a, 1);
		else
			pb_smart(a, b);
		limit--;
	}
	sort_3(a);
}
