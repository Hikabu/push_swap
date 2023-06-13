/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:00:49 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 17:44:47 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	parcfill(char **av, t_push **a)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	if (empty(av))
		erwrite(av);
	str = ft_strdup(av[i]);
	i++;
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp && !*tmp)
			erwrite(av);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	spli(str, a);
	free(str);
}

int	stack_size(t_push *a)
{
	int		size;
	t_push	*tmp;

	size = 0;
	tmp = (a);
	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		size++;
	}
	a = tmp;
	return (size);
}

void	forinstruct(t_push	**a, t_push **b, char *str, char **av)
{
	if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(a, b);
	else
		erwrite(av);
}

void	instruct(t_push **a, t_push **b, char **av)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str || !*str)
		{
			free (str);
			break ;
		}
		forinstruct(a, b, str, av);
		free(str);
	}
}

int	main(int ac, char **av)
{
	t_push	*a;
	t_push	*b;
	int		size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		parcfill(av, &a);
		size = stack_size(a);
		giveinx(&a, size);
		instruct(&a, &b, av);
		if (sorted(a) == 1 && !b)
			write(1, "OK\n", 3);
		else if ((sorted(a) == 0 || b))
			write(1, "KO\n", 3);
	}
}
