/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/09 19:57:31 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stddef.h>
# include<limits.h>
# include<stdlib.h>
# include<fcntl.h>
# include<sys/wait.h>
# include<libft.h>

typedef struct s_push
{
	int		inx;
	int 	val;
	int		nbr;
	struct	s_push *next;
	struct	s_push *prev;
}	t_push;

void	vse_errorbl(char **split);
int		empty(char **av);
t_push	*ft_pushlast(t_push *lst);
int		stack_size(t_push *a);
void	spli(char *str, t_push **a);
void	parcfill(char **av, t_push **a);
t_push	filla(char **str, t_push **a);
void	wrb(t_push *b);
void	pusha(t_push **a, t_push **b, int size);
int		finmax(t_push **b);



t_push	filla(char **str, t_push **a);
void	swap(t_push **a);
void	sa(t_push **a);
void	sb(t_push **b);
void	ss(t_push **a, t_push**b);
void	push(t_push **to, t_push **from);
void	pa(t_push **to, t_push **from);
void	pb(t_push **from, t_push **to);
void	rotate(t_push **a);
void	ra(t_push **a);
void	rb(t_push **b);
void	reverse(t_push **a);
void	rra(t_push **a);
void	rrb(t_push **b);
void	rrr(t_push **a, t_push **b);
void	sort(t_push **a, t_push **b, int size);

void	giveinx(t_push **a, int size);
int		ft_pushsize(t_push *lst);
void	butterfly(t_push **a, t_push **b, int n);
int		my_sqrt(int n);
int		fin(int n);
void	push_swap(t_push **a, t_push **b, int size);
int		sorted(t_push *a);
void	trisort(t_push **a);
void	chersort(t_push **a, t_push **b);
void	fivsort(t_push **a, t_push **b);

#endif
