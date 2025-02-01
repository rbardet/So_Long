/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:29:20 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:35:52 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	get_item_nbr(char **map)
{
	int	x;
	int	y;
	int	item_nbr;

	check_mapform(map);
	check_mapsize(map);
	x = 0;
	y = 0;
	item_nbr = 0;
	while (map[y] != NULL)
	{
		if (map[y][x] == 'C')
			item_nbr++;
		if (map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	return (item_nbr);
}

int	check_mapform(char **map)
{
	int	y;
	int	x;
	int	x2;

	y = 1;
	x = ft_strlen(map[0]);
	x2 = 0;
	while (map[y] != NULL)
	{
		x2 = ft_strlen(map[y]);
		if (x2 != x)
		{
			free_map(map);
			form_error();
		}
		y++;
	}
	return (0);
}
