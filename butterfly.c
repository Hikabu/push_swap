/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/08 20:16:10 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	butterfly(t_push **a, t_push **b, int n)
{
	int	counter;
	int	i;
	int siz;

	siz = ft_pushsize(*a);

	i = 0;
	counter = 0;
	while(i < siz)
	{
		if ((*a)->inx <= counter)
		{
			pb(a, b);
			// printf("%d ", (*b)->nbr);
			rb(b);
			counter++;
		}
		else if ((*a)->inx <= counter + n)
		{
			pb(a, b);
			// printf("%d ", (*b)->nbr);
			counter++;
		}
		else
			ra(a);
		i++;
	}
	wrb(*a);
}


void	wrb(t_push *b)
{
	t_push	*cur;

	cur = b;
	while (cur)
	{
		printf("%d ", cur->nbr);
		cur = cur->next;
	}
}

