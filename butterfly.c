/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 15:44:20 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_push **a, t_push **b, int siz)
{
	int	counter;
	int	n;

	n = siz;
	counter = 1;
	while (*a)
	{
		if ((*a)->inx <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->inx <= counter + n)
		{
			pb(a, b);
			counter++;
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
	while (current)
	{
		if (current->inx > max)
		max = current->inx;
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
	while (b->inx != max)
	{
		i++;
		b = b->next;
	}
	return (i);
}
