#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		ft_putstr_fd("ss\n", 1);
}
