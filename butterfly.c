/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/07 13:15:46 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_push **a, t_push **b, int n)
{
	int	counter;

	counter = 0;
	if ((*a)->inx <= counter)
	{
		pb(b, a);
		rb(b);
		counter++;
	}
	else if ((*a)->inx <= counter + n)
	{
		pb(b, a);
		counter++;
	}
	else
		ra(a);
}

void	push_list_a(t_push **a, t_push **b, int size)
{
	int	max;

	max = 0;
	while (b)
	{
	max = find_max(b);
		if (max <= size / 2)
		{
			while (max-- >= 1)
				rb(b);
			pa(a, b);
			size--;
		}
		else
		{
			while (size - max)
			{
				rrb(b);
				max++;
			}
			pa(a, b);
			size--;
		}
	}
}

// void	sort(t_push **a, t_push **b, int size)
// {
// 	if (size > 5 && size <= 100)
// 	{
// 		butterfly(a, b, 15);
// 		push_list_a(a, b, size);
// 	}
// }

