/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:29:23 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 03:58:27 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

void	door(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	if (data->map[data->y - 1][data->x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			width * data->x, height * (data->y - 1));
	}
	else if (data->map[data->y + 1][data->x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			width * data->x, height * (data->y + 1));
	}
	else if (data->map[data->y][data->x + 1] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			width * (data->x + 1), height * data->y);
	}
	else if (data->map[data->y][data->x - 1] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			width * (data->x - 1), height * data->y - 1);
	}
}

void	move_up(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	data->y -= 1;
	if (data->map[data->y][data->x] == '1')
	{
		data->y += 1;
		return ;
	}
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr != 0)
	{
		move_up2(data);
		return ;
	}
	else if (data->map[data->y][data->x] == 'D')
		ft_free(data);
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr == 0)
		ft_free(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * data->x, height * (data->y + 1));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
		width * data->x, height * data->y);
	return ;
}

void	move_down(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	data->y += 1;
	if (data->map[data->y][data->x] == '1')
	{
		data->y -= 1;
		return ;
	}
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr != 0)
	{
		move_down2(data);
		return ;
	}
	else if (data->map[data->y][data->x] == 'D')
		ft_free(data);
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr == 0)
		ft_free(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * data->x, height * (data->y - 1));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
		width * data->x, height * data->y);
	return ;
}

void	move_left(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	data->x -= 1;
	if (data->map[data->y][data->x] == '1')
	{
		data->x += 1;
		return ;
	}
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr != 0)
	{
		move_left2(data);
		return ;
	}
	else if (data->map[data->y][data->x] == 'D')
		ft_free(data);
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr == 0)
		ft_free(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * (data->x + 1), height * data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
		width * data->x, height * data->y);
	return ;
}

void	move_right(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	data->x += 1;
	if (data->map[data->y][data->x] == '1')
	{
		data->x -= 1;
		return ;
	}
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr != 0)
	{
		move_right2(data);
		return ;
	}
	else if (data->map[data->y][data->x] == 'D')
		ft_free(data);
	else if (data->map[data->y][data->x] == 'E' && data->item_nbr == 0)
		ft_free(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * (data->x - 1), height * data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
		width * data->x, height * data->y);
	return ;
}
