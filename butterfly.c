/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/08 15:06:07 by vfedorov         ###   ########.fr       */
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

// void	pusha(t_push **a, t_push **b, int size)
// {
// 	int	max;

// 	max = 0;
// 	while (b)
// 	{
// 		max = finmax(b);
		
// 	}
// }

// void	sort(t_push **a, t_push **b, int size)
// {
// 	if (size > 5 && size <= 100)
// 	{
// 		butterfly(a, b, 15);
// 		push_list_a(a, b, size);
// 	}
// }

