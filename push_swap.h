/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:55 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:55 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line_bonus.h"
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				in_lis;
	int				lis_len;
	struct s_stack	*next;
}	t_stack;

int		hendel_error(t_stack *a);
void	parsing(int ac, char **av, t_stack **a);
int		ft_atoi2(char *str, int *error);
void	free_stack(t_stack **stack);
int		error_arg(int ac, char **av);
int		is_sorted(t_stack *stack);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);

int		stack_size(t_stack *s);
void	asined_index(t_stack *stack);
void	update_pos(t_stack *stack);
void	find_lis(t_stack *stack);
void	push_non_lis(t_stack **a, t_stack **b);
void	set_target_pos(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
int		to_abs(int x);
void	move_cheapest(t_stack **a, t_stack **b);
void	final_rotate(t_stack **a);
void	sort_large(t_stack **a, t_stack **b);

void	run_checker(t_stack **a, t_stack **b);
int		apply_inst(char *s, t_stack **a, t_stack **b);
int		is_sorted_idx(t_stack *a);

int		non_digit(char *str);
void	do_rotate_a(t_stack **a, int *cost_a);
void	do_rotate_b(t_stack **b, int *cost_b);
void	norm1(t_stack *s);
t_stack	*pred(t_stack *head, t_stack *end, int need);
t_stack	*best_end(t_stack *s);

#endif
