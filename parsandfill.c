/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsandfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:25:31 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/12 19:34:59 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spli(char *str, t_push **a)
{
	char	**split;

	split = ft_split(str, ' ');

	if (!split)
	//*split
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	vse_errorbl(split);
	filla(split, a);
	if(*a)
		free_arr(split);
}

void	free_arr(char **str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
#include <stdio.h>

void	parcfill(char **av, t_push **a)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	if (empty(av))
		erwrite(av);
	str = ft_strdup(av[i]);
	i++;
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp && !*tmp)
			erwrite(av);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	spli(str, a);
	free(str);
}

// char	*ft_strjoin1(char *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!dest || s2 == 0)
// 		return (0);
// 	while (s1[i])
// 		dest[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		dest[j++] = s2[i++];
// 	if (*s1)
// 		free(s1);
// 	dest[j] = 0;
// 	return (dest);
// }
// char	*ft_strdup1(char *s1)
// {
// 	char	*der;
// 	int		i;
// 	int		g;

// 	i = 0;
// 	while (s1[i])
// 		i++;
// 	der = malloc(sizeof(char) * (i + 1));
// 	if (!(der))
// 		return (0);
// 	g = 0;
// 	while (s1[g])
// 	{
// 		der[g] = s1[g];
// 			g++;
// 	}
// 	der[g] = '\0';
// 	return (der);
// }
// void	parcfill(char **av, t_push **a)
// {
// 	char	*etc;
// 	char	*tmp;
// 	int		i;
	
// 	tmp = "";
// 	i = 1;
// 	while(av[i])
// 	{
// 		etc = ft_strdup1(av[i]);
// 		tmp = ft_strjoin(etc, " ");
// 		free(etc);
// 		printf("in loop: %s\n", tmp);	
// 		free(tmp);
// 		i++;
// 	}
// 	system("leaks push_swap");
// 	printf("out of loop: %s\n", tmp);
// 	spli(tmp, a);
// }

t_push	*ft_pushlast(t_push *lst)
{
	t_push	*tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst-> next == NULL)
			return (lst);
		tmp = lst;
		lst = lst->next;
		lst->prev = tmp;
	}
	return (lst);
}

// typedef struct s_push
// {
// 	int				inx;
// 	int				val;
// 	int				nbr;
// 	struct s_push	*next;
// 	struct s_push	*prev;
// }		t_push;

t_push	filla(char **str, t_push **a)
{
	t_push	*t;
	int		i;

	i = 0;
	while (str[i])
	{
		t = (t_push *)malloc(sizeof(t_push));
		t->nbr = ft_atoi(str[i]);
		t->inx = -1;
		t->next = NULL;
		t->prev = ft_pushlast(*a);
		if (*a)
			ft_pushlast(*a)->next = t;
		else
			*a = t;
		i++;
	}
	//rewrite
	return (**a);
}

int	stack_size(t_push *a)
{
	int	size;
	t_push	*tmp;

	size = 0;
	tmp = (a);
	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		size++;
	}
	a = tmp;
	return (size);
}
