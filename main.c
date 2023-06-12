/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:45:51 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 19:32:39 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_push *a)
{
	while (a && a->next)
	{
		if (a->next && a->inx > a->next->inx)
			return (0);
		a = a->next;
	}
	return (1);
}

void	butter_fly(t_push **a, t_push**b, int size)
{
	if (size > 5 && size < 30)
	{
		butterfly(a, b, size / 2);
		pusha(a, b, size);
	}
	else if (size >= 30 && size < 50)
	{
		butterfly(a, b, size / 4);
		pusha(a, b, size);
	}
	else if (size >= 50 && size < 500)
	{
		butterfly(a, b, size / 8);
		pusha(a, b, size);
	}
	else if (size >= 500)
	{
		butterfly(a, b, size / 16);
		pusha(a, b, size);
	}
}

void	push_swap(t_push **a, t_push **b, int size)
{
	if (size == 2 && (*a)->inx > (*a)->next->inx)
		sa(a);
	else if (size == 3)
		trisort(a);
	else if (size == 4)
		chersort(a, b);
	else if (size == 5)
		fivsort(a, b);
	else if (size > 5)
		butter_fly(a, b, size);
}

int	main(int ac, char **av)
{
	t_push	*a;
	t_push	*b;
	int		size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		
		parcfill(av, &a);
		// system("leaks push_swap");
		size = stack_size(a);
		giveinx(&a, size);

		if (!sorted(a))
		{
			push_swap(&a, &b, size);
			
		}
	}
		system("leaks push_swap");
	return (0);
}
