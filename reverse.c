/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:21:37 by vfedorov          #+#    #+#             */
/*   Updated: 2023/05/30 16:44:09 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_push **a)
{
	t_push	*top;
	t_push	*tail;

	if (*a && (*a)->next)
	{
		tail = *a;
		top = ft_pushlast(tail);
		*a = tail->next;
		tail->next = NULL;
		top->next = tail;
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