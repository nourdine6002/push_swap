#include "push_swap.h"

void	norm1(t_stack *s)
{
	t_stack	*i;
	t_stack	*j;

	i = s;
	while (i)
	{
		j = s;
		while (j != i)
		{
			if (j->index < i->index && j->lis_len + 1 > i->lis_len)
				i->lis_len = j->lis_len + 1;
			j = j->next;
		}
		i = i->next;
	}
}
