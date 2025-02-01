/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:22:16 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:44:12 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

void	check_type(char **map, t_data *data, int x, int y)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	if (map[y][x] == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
			width * x, height * y);
		return ;
	}
	else if (map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			width * x, height * y);
		return ;
	}
	else
		check_type2 (map, data, x, y);
}

void	check_type2(char **map, t_data *data, int x, int y)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	if (map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			width * x, height * y);
		return ;
	}
	else if (map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->item,
			width * x, height * y);
		return ;
	}
	else if (map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			width * x, height * y);
		return ;
	}
	else
		check_type3 (map, data, x, y);
}

void	check_type3(char **map, t_data *data, int x, int y)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	if ((map[y][x] == 'D') && (data->mouv % 2 == 0))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy,
			width * x, height * y);
		return ;
	}
	else if ((map[y][x] == 'D') && (data->mouv % 2 != 0))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy2,
			width * x, height * y);
		return ;
	}
}
