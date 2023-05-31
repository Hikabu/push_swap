/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:46:48 by vfedorov          #+#    #+#             */
/*   Updated: 2023/05/30 16:44:23 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push **a)
{
    int	first;
    int	second;

    if (*a &&(*a)->next)
    {
        first = (*a)->nbr;
        second = (*a)->next->nbr;
        (*a)->nbr = second;
        (*a)->next->nbr = first;
    }
}
void	sa(t_push **a)
{
    swap(a);
    write(1, "sa\n", 3);
	// printf("%d", (*a)->nbr);
}

void	sb(t_push **b)
{
    swap(b);
	// printf("%d", (*b)->nbr);
    write(1, "sb\n", 3);
}
void	ss(t_push **a, t_push**b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}