/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tri_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:46:09 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 16:44:03 by valeriafedo      ###   ########.fr       */
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

	i = finmax(a);
	if (i == 3)
		rra(a);
	else if (i == 2)
	{
		rra(a);
		rra(a);
	}
	else if (i == 1)
		ra(a);
	pb(b, a);
	trisort(a);
	pa(b, a);
	ra(a);
}
void	fivsort(t_push **a, t_push **b)
{
	while ((*a)->inx != 1)
		ra(a);
	pb(a, b);
	// wrb(*a);
	while ((*a)->inx != 2)
		ra(a);
	pb(a, b);
	// wrb(*a);
	trisort(a);
	pa(b, a);
	// wrb(*a);
	pa(b, a);
	
}
