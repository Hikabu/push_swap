/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:26:04 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 15:57:42 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_push **to, t_push **from)
{
	t_push	*tmp;

	tmp = *from;
	if (*from)
		(*from) = (*from)->next;
	else
		return ;
	tmp->next = *to;
	(*to) = tmp;
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
