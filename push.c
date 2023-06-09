/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:26:04 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 15:52:37 by valeriafedo      ###   ########.fr       */
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
		// printf("%d\n", (*to)->nbr);
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
