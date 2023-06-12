/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsandfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:25:31 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 20:04:01 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spli(char *str, t_push **a)
{
	char	**split;

	split = ft_split(str, ' ');

	if (!split)
	//*split
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	vse_errorbl(split);
	filla(split, a);
	if(*a)
		free_arr(split);
}

void	free_arr(char **str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
#include <stdio.h>

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

t_push	*ft_pushlast(t_push *lst)
{
	t_push	*tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst-> next == NULL)
			return (lst);
		tmp = lst;
		lst = lst->next;
		lst->prev = tmp;
	}
	return (lst);
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

int	stack_size(t_push *a)
{
	int	size;
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
