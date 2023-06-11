/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:03:06 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/10 18:11:47 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_duper(char **split)
{
	int		i;
	int		f;
	int		cnt;
	
	i = 0;
	while (split[i])
	{
		while (*split[i] == '0' && *(split[i] + 1) == '0')
			split[i]++;
		cnt = 0;
		f = 0;		
		while (split[f])
		{
			if (ft_strncmp(split[i], split[f], ft_strlen(split[i])) == 0 
				&& ft_strncmp(split[i], split[f], ft_strlen(split[f])) == 0)
					cnt++;
			if (cnt > 1)
			{
				write(2, "Error\n", 6);
				exit(1);	
			}
			f++;
		}
		i++;
	}
}

void	overflow(char **split)
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
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	chedigit(char **str)
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
				write(2, "Error\n", 6);
				exit(1);	
			}		
			if (ft_isdigit(*tmp))
				tmp++;
		}
		str++;
	}
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

void	vse_errorbl(char **split)
{
	ft_duper(split);
	overflow(split);
	chedigit(split);
}
