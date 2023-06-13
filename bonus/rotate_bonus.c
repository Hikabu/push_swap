/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:25:11 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 05:14:16 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

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
}

void	rb(t_push **b)
{
	rotate (b);
}

void	rr(t_push **a, t_push **b)
{
	rotate (a);
	rotate (b);
}

void	erwrite(char **av)
{
	(void)av;
	write(2, "Error\n", 6);
	exit(1);
}
