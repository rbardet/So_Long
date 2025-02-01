/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:28:13 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 01:14:58 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	flood_fill(int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'D')
		return ;
	map[y][x] = 'F';
	flood_fill(x, y - 1, map);
	flood_fill(x, y + 1, map);
	flood_fill(x - 1, y, map);
	flood_fill(x + 1, y, map);
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	check_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map);
				path_error();
			}
			x++;
		}
		y++;
		x = 0;
	}
}

char	**remap_reader(char *argv)
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
