#include "push_swap.h"

static int	is_repite(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->val == j->val)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

static int	error_arg_hlp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			if (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				return (1);
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			return (1);
	}
	return (0);
}

int	error_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (error_arg_hlp(av[i]) == 1 || non_digit(av[i]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	hendel_error(t_stack *a)
{
	if (is_repite(a) == 1)
		return (1);
	return (0);
}
