/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:09:52 by nodoulah          #+#    #+#             */
/*   Updated: 2026/01/18 06:09:52 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(char *str, int *error)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	while (str[i] == ' ')
		i++;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			*error = 1;
		i++;
	}
	return ((int)(res * neg));
}

static void	to_list(int n, t_stack **a)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->val = n;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void	parse_string_to_list(char *str, t_stack **a)
{
	int		j;
	int		error;
	int		n;
	char	**spliter;

	spliter = ft_split(str, ' ');
	if (!spliter)
		return ;
	free_max_min(spliter);
	j = 0;
	while (spliter[j])
	{
		error = 0;
		n = ft_atoi2(spliter[j], &error);
		to_list(n, a);
		free(spliter[j]);
		j++;
	}
	free(spliter);
}

void	parsing(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		parse_string_to_list(av[i], a);
		i++;
	}
}
