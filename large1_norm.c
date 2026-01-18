#include "push_swap.h"

int	non_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	asined_index(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*cmp;
	int		index;

	tmp1 = stack;
	while (tmp1)
	{
		index = 0;
		cmp = stack;
		while (cmp)
		{
			if (tmp1->val > cmp->val)
				index++;
			cmp = cmp->next;
		}
		tmp1->index = index;
		tmp1 = tmp1->next;
	}
}

void	update_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

void	find_lis(t_stack *s)
{
	t_stack	*i;
	t_stack	*end;
	int		len;

	i = s;
	while (i)
	{
		i->in_lis = 0;
		i->lis_len = 1;
		i = i->next;
	}
	i = s;
	norm1(s);
	end = best_end(s);
	len = end->lis_len;
	while (end && len > 0)
	{
		end->in_lis = 1;
		len--;
		if (len == 0)
			break ;
		end = pred(s, end, len);
	}
}
