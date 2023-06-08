/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tri_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:46:09 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/08 19:05:40 by vfedorov         ###   ########.fr       */
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

// void	chersor(t_push **a)
// {
// 	whl
// }
void	fivsort(t_push **a, t_push **b)
{
	while ((*a)->inx != 1)
		ra(a);
	pb(a, b);
	while ((*a)->inx != 2)
		ra(a);
	pb(a, b);
	trisort(a);
	pa(a, b);
	pa(a, b);
}
