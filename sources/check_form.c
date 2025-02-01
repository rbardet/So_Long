/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:00:57 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/09 01:36:00 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	check_mapsize(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		if (x > 30)
		{
			free_map(map);
			size_error();
		}
		if (map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	if (y > 16)
	{
		free_map(map);
		size_error();
	}
	return (0);
}
