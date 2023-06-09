/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 19:45:28 by valeriafedo      ###   ########.fr       */
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
			// printf("%d ", (*b)->nbr);
			rb(b);
			counter++;
			i++;
		}
		else if ((*a)->inx <= counter + n)
		{
			pb(a, b);
			// printf("%d ", (*b)->nbr);
			counter++;
			i++;
		}
		else
			ra(a);
	}
	// wrb(*b);
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
	printf("%d", max);
	return (max);
}

int	my_sqrt(int n)
{
	int	i;

	i = 1;
	while (n / i != i)
		i++;
	return (i);
}

int	fin(int n)
{
	int	i;

	i = 1;
	while (n)
	{
		n /= 5;
		i++;
	}
	return (i);
}