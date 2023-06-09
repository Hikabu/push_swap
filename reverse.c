/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:21:37 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 23:34:25 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		
		// dprintf(1, "%d", (*a)->nbr);
		// dprintf(1, "%d", (*a)->next->nbr);
		// dprintf(1, "%d", (*a)->next->next->nbr);
	}
}

void	rra(t_push **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_push **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push **a, t_push **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrb\n", 4);
}