/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:45:51 by vfedorov          #+#    #+#             */
/*   Updated: 2023/05/31 13:50:55 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_push *a)
{
	while (a->nbr)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
void	push_swap(t_push **a, int size)
{
	if (size == 2 && !sorted(*a))
		sa(a);
	else if (size == 3 && !sorted(*a))
		trisort(a);
	//else if(size > 3 && !sorted(*a))
		//sortiruiy(a, b)
	
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
		pb(&a, &b);
		sa(&a);
		pb(&a, &b);
		sb(&b);
		parcfill(av, &a);
		size = stack_size(a);
		push_swap(&a, size);
		givindex(a, size);
		
	


		
		t_push *tmp;
		tmp = a;
		while (tmp)
		{
			printf("%d ", tmp->nbr);
			tmp = tmp->next;			
		}
	}
	return (0);
}



// pb(&a, &b);
		// ra(&a);
		// pb(&a, &b);
		// ra(&a);
		// sa(&a);
		// ra(&a);
		// pa(&b, &a);
		// pa(&b, &a);
		// pb(&b, &a);
		// pb(&b, &a);
		// sb(&b);
		// rotate(&a);
		// write(1, "\n", 2);
		// reverse(&a);
		// write(1, "\n", 2);