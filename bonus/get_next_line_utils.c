/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:30:48 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/13 03:59:29 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		r;
	char		*ano_s;

	ano_s = malloc(sizeof(*s) * (len + 1));
	if (ano_s == 0)
		return (NULL);
	i = 0;
	r = 0;
	while (s[i])
	{
		if (i >= start && r < len)
		{
			ano_s[r] = s[i];
			r++;
		}
		i++;
	}
	ano_s[r] = '\0';
	return (ano_s);
}

char	*ft_strdup(const char *s1)
{
	char	*der;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	der = malloc(sizeof(char) * (i + 1));
	if (!der)
		return (0);
	i = 0;
	while (s1[i])
	{
		der[i] = s1[i];
			i++;
	}
	der[i] = '\0';
	return (der);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		dl1;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	dl1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (dl1 + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[dl1++] = s2[i];
		i++;
	}
	str[dl1] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
