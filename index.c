/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:32:03 by vfedorov          #+#    #+#             */
/*   Updated: 2023/05/31 13:50:13 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	givindex(t_push *a, int s_size)
{
	t_push	*stack;
	t_push	*highest;
	int		value;

	while((s_size--) > 0)
	{
		stack = a;
		value = INT_MIN;
		highest = NULL;
		while(stack)
		{
			if (stack->val == value && stack->inx == 0)
				stack->inx = 1;
			if (stack->val > value && stack->inx == 0)
			{
				value = stack->val;
				highest = stack;
				stack = a;
			}
			else
				stack = stack->next;
		}
		if (highest != NULL)
			highest->inx = s_size;
	}
}