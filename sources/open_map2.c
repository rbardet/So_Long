/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:50:14 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 05:24:43 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

void	show_map2(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			check_type3(data->map, data, x, y);
			x++;
		}
		y++;
	}
}

int	animated_sprite(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	if (data->timer == 100000)
		data->timer = 0;
	data->timer++;
	if (data->timer < 50000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			width * data->x, height * data->y);
		return (0);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player3,
			width * data->x, height * data->y);
		return (0);
	}
}
