/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:50:10 by vfedorov          #+#    #+#             */
/*   Updated: 2023/03/02 12:37:27 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *tmp_str_dat, char *org)
{
	int		read_lf;
	char	*reserv;

	read_lf = 1;
	reserv = NULL;
	while (read_lf != '\0')
	{
		read_lf = read(fd, tmp_str_dat, BUFFER_SIZE);
		if (read_lf == -1)
			return (0);
		else if (read_lf == 0)
			break ;
		tmp_str_dat[read_lf] = '\0';
		if (!org)
			org = ft_strdup("");
		reserv = org;
		org = ft_strjoin(reserv, tmp_str_dat);
		free(reserv);
		reserv = NULL;
		if (ft_strchr(tmp_str_dat, '\n'))
			break ;
	}
	return (org);
}

char	*rem(char *line)

{
	size_t	count;
	char	*reserv;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	reserv = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*reserv == '\0')
	{
		free(reserv);
		reserv = NULL;
	}
	line[count + 1] = '\0';
	return (reserv);
}

char	*get_next_line(int fd)

{
	char		*line;
	char		*buf;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_fd(fd, buf, res);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	res = rem(line);
	return (line);
}
// #include<stdio.h>
// int main()
// {
// 	int			fd;
// 	char	c = 0;

// 	fd = open("don.txt", O_RDONLY);
// 	// read(fd, &c, 1);
// 	// printf("%c", c);
// 	printf("%s", get_next_line(fd));

// }
