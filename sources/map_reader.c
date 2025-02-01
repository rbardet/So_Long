/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:57:22 by rbardet-          #+#    #+#             */
/*   Updated: 2024/12/12 06:25:13 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**map_reader(char *argv)
{
	char	**map;
	char	*temp;
	int		fd;
	int		line;
	int		nbline;

	line = 0;
	nbline = count_line(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	map = malloc(sizeof(char *) * (nbline + 1));
	if (!map)
		exit(EXIT_FAILURE);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map[line] = temp;
		line++;
		temp = get_next_line(fd);
	}
	map[line] = NULL;
	close(fd);
	return (map);
}
// int main(int argc, char **argv)
// {
// 	char **str;
// 	int a;

// 	a = 0;
// 	if (argc != 2)
// 		return (1);
// 	str = map_reader(argv[1]);
// 	if (str == NULL)
// 	{
// 		return 1;
// 	}
// 	while (str[a])
// 	{
// 		printf("%s", str[a]);
// 		a++;
// 	}
// 	a = 0;
// 	while (str[a] != NULL)
// 	{
// 		free(str[a]);
// 		a++;
// 	}
// 	free(str);
// 	return 0;
// }
