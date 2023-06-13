/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:34:10 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 05:15:18 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	spli(char *str, t_push **a)
{
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	vse_errorbl(split);
	filla(split, a);
	if (*a)
		free_arr(split);
}

void	giveinx(t_push **a, int size)
{
	int		i;
	t_push	*tmp;
	int		min;

	i = 1;
	while (i <= size)
	{
		tmp = *a;
		min = INT_MAX;
		while (tmp)
		{
			if (tmp->inx == -1 && tmp->nbr < min)
				min = tmp->nbr;
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp->nbr != min || tmp->inx != -1)
		{
			tmp = tmp->next;
		}
		tmp->inx = i;
			i++;
	}
}

void	free_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_push	filla(char **str, t_push **a)
{
	t_push	*t;
	int		i;

	i = 0;
	while (str[i])
	{
		t = (t_push *)malloc(sizeof(t_push));
		t->nbr = ft_atoi(str[i]);
		t->inx = -1;
		t->next = NULL;
		t->prev = ft_pushlast(*a);
		if (*a)
			ft_pushlast(*a)->next = t;
		else
			*a = t;
		i++;
	}
	return (**a);
}

void	vse_errorbl(char **split)
{
	if (ft_duper(split))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (overflow(split))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (chedigit(split))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
