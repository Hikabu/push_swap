/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:03:06 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 05:13:26 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	ft_duper(char **split)
{
	int		i;
	int		f;
	int		a;

	i = 0;
	while (split[++i])
	{
		f = 0;
		while (f < i)
		{
			a = ft_strlen(split[i]);
			if (ft_strlen(split[i]) < ft_strlen(split[f]))
				a = ft_strlen(split[f]);
			if (!ft_strncmp(split[i], split[f], a))
			{
				return (-1);
			}
			f++;
		}
	}
	return (0);
}

int	overflow(char **split)
{
	char	*nmb;
	int		i;

	i = 0;
	while (split[i])
	{
		nmb = ft_itoa(ft_atoi(split[i]));
		if (ft_strncmp(nmb, split[i], ft_strlen(nmb) != 0
				&& ft_strncmp(nmb, split[i], ft_strlen(split[i]) != 0)))
		{
			return (-1);
		}
		free(nmb);
		i++;
	}
	return (0);
}

int	chedigit(char **str)
{
	char	*tmp;

	while (*str)
	{
		tmp = *str;
		while (*tmp)
		{	
			if (tmp[0] == '-')
				tmp++;
			if (!ft_isdigit(*tmp))
			{
				return (-1);
			}		
			if (ft_isdigit(*tmp))
				tmp++;
		}
		str++;
	}
	return (0);
}

int	empty(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (*av[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	sorted(t_push *a)
{
	while (a && a->next)
	{
		if (a->next && a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
