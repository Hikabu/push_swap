/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:25:11 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 15:58:28 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
