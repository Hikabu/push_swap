/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 04:45:38 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_BONUS_H
# define PUSH_BONUS_H

# include<unistd.h>
# include<stdio.h>
# include<stddef.h>
# include<limits.h>
# include<stdlib.h>
# include<fcntl.h>
# include<sys/wait.h>
# include<libft.h>
# include "get_next_line.h"

typedef struct s_push
{
	int				inx;
	int				val;
	int				nbr;
	struct s_push	*next;
	struct s_push	*prev;
}		t_push;

void			vse_errorbl(char **split);
int				empty(char **av);
int				ft_duper(char **split);
void			free_arr(char **str);
void			swap(t_push **a);
void			sa(t_push **a);
void			sb(t_push **b);
void			ss(t_push **a, t_push**b);
void			push(t_push **to, t_push **from);
void			pa(t_push **to, t_push **from);
void			pb(t_push **from, t_push **to);
void			rotate(t_push **a);
void			ra(t_push **a);
void			rb(t_push **b);
void			rr(t_push **a, t_push **b);
void			reverse(t_push **a);
void			rra(t_push **a);
void			rrb(t_push **b);
void			rrr(t_push **a, t_push **b);
t_push			*ft_pushlast(t_push *lst);
void			erwrite(char **av);
int				overflow(char **split);
int				chedigit(char **str);
void			spli(char *str, t_push **a);
t_push			filla(char **str, t_push **a);
t_push			*ft_pushlast(t_push *lst);
void			vse_errorbl(char **split);
void			instruct(t_push **a, t_push **b, char **av);
void			giveinx(t_push **a, int size);
int				stack_size(t_push *a);

int				sorted(t_push *a);
int				ft_wordcount(char const *s, char c);
char			**ft_split(char const *s, char c);
int				ft_len(char const *s, char c);

#endif
