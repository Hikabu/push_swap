/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:21:37 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 03:44:29 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	reverse(t_push **a)
{
	t_push	*top;
	t_push	*tail;
	t_push	*pretail;

	if (*a && (*a)->next)
	{
		tail = *a;
		top = ft_pushlast(tail);
		top->next = tail;
		if (top-> prev)
		{
			pretail = top->prev;
			pretail->next = NULL;
			top->prev = NULL;
		}
		*a = top;
	}
}

void	rra(t_push **a)
{
	reverse(a);
}

void	rrb(t_push **b)
{
	reverse(b);
}

void	rrr(t_push **a, t_push **b)
{
	reverse(a);
	reverse(b);
}
