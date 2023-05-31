/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:25:11 by vfedorov          #+#    #+#             */
/*   Updated: 2023/05/30 20:25:52 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate(t_push **a)
// {
// 	t_push	*tmp;

// 	if (*a && (*a)->next)
// 	{
// 		tmp = *a;
// 		*a = (*a)->next;
// 		if (*a)
// 			(*a)->prev = NULL;
// 		while ((*a)->next)
// 		{
// 			*a = (*a)->next;
// 		}
// 	}
// }

void	rotate(t_push **a)
{
	t_push	*top;
	t_push	*tail;

	if (*a && (*a)->next)
	{
		top = *a;
		tail = ft_pushlast(top);
		*a = top->next;
		top->next = NULL;
		tail->next = top;
		// dprintf(1, "%d", (*a)->nbr);
		// dprintf(1, "%d", (*a)->next->nbr);
		// dprintf(1, "%d", (*a)->next->next->nbr);
	}
}

void	ra(t_push **a)
{
	rotate (a);
	write(1, "ra\n", 3);
}

void	rb(t_push **b)
{
	rotate (b);
	write(1, "rb\n", 3);
}