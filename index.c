/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:32:03 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/03 13:41:29 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void giveinx(t_push **a, int size)
{
	int i;
	t_push *tmp;
	int min;

	i = 1;
	while ( i <= size - 1)
	{
		tmp = *a;
		min = INT_MAX;
		while (tmp)
		{
			if (tmp->inx == -1 && tmp->nbr < min)
				min = tmp->nbr;
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp->nbr != min || tmp->inx != -1)
		{
			tmp = tmp->next;
		}
		tmp->inx = i;
		i++;
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

// int	my_sqrt(int n)
// {
// 	int	i;

// 	i = 1;
// 	while (n / i != i)
// 		i++;
// 	return (i);
// }

// int	fin(int n)
// {
// 	int	i;

// 	i = 1;
// 	while (n)
// 	{
// 		n /= 5;
// 		i++;
// 	}
// 	return (i);
// }