/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:46:48 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 05:14:57 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	swap(t_push **a)
{
	int	first;
	int	second;

	if (*a && (*a)->next)
	{
		first = (*a)->nbr;
		second = (*a)->next->nbr;
		(*a)->nbr = second;
		(*a)->next->nbr = first;
	}
}

void	sa(t_push **a)
{
	swap(a);
}

void	sb(t_push **b)
{
	swap(b);
}

void	ss(t_push **a, t_push **b)
{
	swap(a);
	swap(b);
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
