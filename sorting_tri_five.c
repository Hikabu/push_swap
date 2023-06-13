/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tri_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:46:09 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 05:08:03 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trisort(t_push **a)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		sa(a);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		ra(a);
	if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		sa(a);
		ra(a);
	}
	if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		sa(a);
}

void	chersort(t_push **a, t_push **b)
{
	int	i;

	wrb(*b);
	i = finmin(a);
	if (i == 1)
		ra(a);
	else if (i == 2)
	{
		rra(a);
		rra(a);
	}
	else if (i == 3)
		rra(a);
	pb(a, b);
	trisort(a);
	pa(b, a);
}

void	fivsort(t_push **a, t_push **b)
{
	while ((*a)->inx != 1)
		ra(a);
	pb(a, b);
	while ((*a)->inx != 2)
		ra(a);
	pb(a, b);
	trisort(a);
	pa(b, a);
	pa(b, a);
}
