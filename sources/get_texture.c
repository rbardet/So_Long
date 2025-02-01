/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:05:51 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:17:47 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

t_data	*get_texture(t_data *data)
{
	int			height;
	int			width;

	height = GRAPHIC_HEIGHT;
	width = GRAPHIC_WIDTH;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/1.xpm",
			&width, &height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/0.xpm",
			&width, &height);
	data->item = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/C.xpm",
			&width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/E.xpm",
			&width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/P.xpm",
			&width, &height);
	data->player2 = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/P2.xpm",
			&width, &height);
	data->player3 = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/P3.xpm",
			&width, &height);
	data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/D.xpm",
			&width, &height);
	data->enemy2 = mlx_xpm_file_to_image(data->mlx_ptr, "graphic/D2.xpm",
			&width, &height);
	return (data);
}
