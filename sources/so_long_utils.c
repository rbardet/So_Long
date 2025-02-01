/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:37:59 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/04 22:51:24 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	count_line(char *argv)
{
	char	*str;
	int		nbline;
	int		fd;

	nbline = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	while (str != NULL)
	{
		nbline++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (nbline);
}

int	width(char *argv)
{
	char	*str;
	int		width;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	width = ft_strlen(str) - 1;
	free(str);
	close(fd);
	return (width);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	int fd = open(argv[1], O_RDONLY);
// 	printf("%d", width(argv[1]));
// 	close(fd);
// 	return (0);
// }
