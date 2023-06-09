/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:32:03 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/03 13:41:29 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void giveinx(t_push **a, int size)
{
	int i;
	t_push *tmp;
	int min;

	i = 1;
	while ( i <= size)
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

void	pusha(t_push **a, t_push **b, int size)
{
	while (size)
	{

		if ((*b)->inx > ft_pushlast(*b)->inx)
		{
			pa(b, a);
			size--;
		}
		else 
		{
			rrb(b);
			pa(b, a);
			size--;
		}
	}
}

int	ft_pushsize(t_push *lst)
{
	int	str_len;

	str_len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		str_len++;
	}
	return (str_len);
}

