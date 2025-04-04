/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:07:54 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/05 03:18:42 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

char	*init_line(char *stash, int *eol_loc)
{
	size_t	len;
	char	*line;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	if (len > 0 && line[len - 1] == '\n')
		*eol_loc = len - 1;
	return (line);
}

size_t	locate_eol(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*extract_line(char *line, char *stash, int *eol_loc, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_check;
	size_t	line_size;

	while (*eol_loc == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			ft_bzero(stash, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_size = locate_eol(buffer);
		ft_strlcpy_gnl(stash, &buffer[line_size], (BUFFER_SIZE + 1));
		buffer[line_size] = '\0';
		line = ft_strjoin_gnl(line, buffer, eol_loc);
		if (read_check == 0)
		{
			ft_bzero(stash, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			eol_loc;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	eol_loc = -1;
	line = init_line(stash[fd], &eol_loc);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(stash[fd], &stash[fd][eol_loc + 1], BUFFER_SIZE + 1);
	line = extract_line(line, stash[fd], &eol_loc, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main(int argc,char **argv)
// {
// 	int a;
// 	int fd;
// 	char *str;

// 	a = 1;
// 	while (a < argc)
// 	{
// 		fd = open(argv[a], O_RDONLY);
// 		if (fd < 0)
// 			return (0);
// 		str = get_next_line(fd);
// 		while (str !=  0)
// 		{
// 			printf("%s", str);
// 			free(str);
// 			str = get_next_line(fd);
// 		}
// 		a++;
// 		close(fd);
// 	}
// 	return(0);
// }
