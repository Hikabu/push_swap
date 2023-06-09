/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:26:04 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/10 00:52:15 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_push **to, t_push **from)
{
	t_push	*tmp;

	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		tmp->next = *to;
		if (*to)
			(*to)->prev = tmp;
		*to = tmp;
		// printf("\n-%d-nbr-\n", (*to)->nbr);
	}
}

void	pa(t_push **from, t_push **to)
{ 
	push(to, from);
	write(1, "pa\n", 3);
}

void	pb(t_push **from, t_push **to)
{
	push(to, from);
	write(1, "pb\n", 3);
}

void	butter_push(t_push **a, t_push **b)
{
	t_push	*tmp;

	
	
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
		if((*a)->prev)
		{
			(*a)->prev = NULL;
		}
		(*b)->prev = NULL;
	}	
	else
	{
		// while((*a)->next)
		// 	(*a) = (*a)->next;
		// tmp = (*a);
		// (*a) -> prev = (*b);
		// (*a) = (*a)->prev;
		// if((*b)-> next)
		// {
		// 	*b = (*b)->next;
		// 	(*b)->prev = NULL;
		// }
		// else 
		// 	(*b) = NULL;
		// // (*a)->prev = NULL;
		// (*a)->next = tmp;
		// (*a)->next->prev = (*a);
		// while ((*a)->prev)
		// 	*a = (*a)-> prev;
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		if (*a)
			(*a)->prev = tmp;
		*a = tmp;
	}
}