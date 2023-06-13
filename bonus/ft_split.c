/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:41:27 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/10 19:14:40 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			wc++;
		while (s[i] != c && s[i])
			i++;
	}
	return (wc);
}

static char	*ft_perevmal(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 1));
	while (start < end)
		str[i++] = s[start++];
	str [i] = '\0';
	return (str);
}

int	ft_len(char const *s, char c)
{
	int		len;
	char	*d;

	d = (char *)s;
	len = 0;
	while (*d && *d != c)
	{
		len++;
		d++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**sst;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	sst = malloc(sizeof(*sst) * (words + 1));
	if (sst == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			sst[i] = ft_perevmal(s, 0, ft_len(s, c));
			s = s + ft_len(s, c);
			i++;
		}
	}
	sst[i] = NULL;
	return (sst);
}	
