/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:45:51 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/10 00:52:34 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_push *a)
{
	while (a->inx)
	{
		if (a->next && a->next->inx < a->inx)
			return (0);
		if (a->next && a->nbr > a->next->nbr)
			return (0);
		if (a->next && a->next->inx)
			a = a->next;
		else
			 break ;
	}
	return (1);
}

void	push_swap(t_push **a, t_push **b, int size)
{
	// int	n;

	// n = my_sqrt(size) + fin(size); 
	if (size == 2 && (*a)->inx < (*a)->next->inx)
		sa(a);
	else if (size == 3 && !sorted(*a))
		trisort(a);
	else if (size == 4 && !sorted(*a))
		chersort(a, b);
	else if (size == 5 && !sorted(*a))
		fivsort(a, b);
	else if (size > 5 && size <= 100)
	{
		butterfly(a, b, 1);
		// wrb(*b);
		
		pusha(a, b, size);
	}
	
}

int main(int ac, char **av)
{
	t_push	*a;
	t_push	*b;
	int		size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		parcfill(av, &a);
		size = stack_size(a);
		giveinx(&a, size);
		// rra(&a);
		push_swap(&a, &b, size);
		// rrb(&b);
		// printf("A:\n");
		// wrb(a);
		// printf("B:\n");
		// // wrb(÷b);
		// wrb(a);
	}
	return (0);
}

