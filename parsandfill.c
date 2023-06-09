/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsandfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:25:31 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 19:52:44 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void spli(char *str, t_push **a)
{
	char	**split;
	
	split = ft_split(str, ' ');
	if (!*split)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	vse_errorbl(split);
	filla(split, a);
}

void	parcfill(char **av, t_push **a)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	if (empty(av))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	str = ft_strdup(av[i]);
	i++;	
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp && !*tmp)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	spli(str, a);
}

t_push	*ft_pushlast(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst-> next == NULL)
			return (lst);
		lst = lst->next;
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

int stack_size(t_push *a)
{
    int size;
    
    size = 0;
    if (!a)
        return (0);
    while (a)
    {
        a = a->next;
        size++;
    }
    return (size);
}
 