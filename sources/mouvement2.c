/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:33:24 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 02:22:12 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

void	move_up2(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * data->x, height * (data->y + 1));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player2,
		width * data->x, height * data->y);
	return ;
}

void	move_down2(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * data->x, height * (data->y - 1));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player2,
		width * data->x, height * data->y);
	return ;
}

void	move_left2(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * (data->x + 1), height * data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player2,
		width * data->x, height * data->y);
	return ;
}

void	move_right2(t_data *data)
{
	int	height;
	int	width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		width * (data->x - 1), height * data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player2,
		width * data->x, height * data->y);
	return ;
}
