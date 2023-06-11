/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/11 18:12:24 by vfedorov         ###   ########.fr       */
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
	counter = 1;
	while(i < siz)
	{
		if ((*a)->inx <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
			i++;
		}
		else if ((*a)->inx <= counter + n)
		{
			pb(a, b);
			counter++;
			i++;
		}
		else
			ra(a);
	}
}


void	wrb(t_push *b)
{
	t_push	*cur;

	cur = b;
	while (cur)
	{
		printf("%d\n", cur->nbr);
		cur = cur->next;
	}
}

int	finmax(t_push **b)
{
	int		max;
	t_push	*current;

	max = INT_MIN;
	current = *b;
	while(current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}
int	findpos(t_push *b)
{
	int	max;
	int	i;

	max = finmax(&b);
	i = 0;
	while (b->nbr != max)
	{
		i++;
		b = b->next;
	}
	return (i);
}
