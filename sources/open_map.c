/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:22:47 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 05:09:00 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

static void	show_map(t_data *data)
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
			check_type(data->map, data, x, y);
			x++;
		}
		y++;
	}
}

static void	show_mouvement(t_data *data)
{
	free(data->mouv_str);
	data->mouv++;
	data->mouv_str = ft_itoa(data->mouv);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
		0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
		64, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 32, COLOR, "Mouvement : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 68, 32, COLOR,
		data->mouv_str);
}

static int	handle_keypress(int keysym, t_data *data)
{
	show_map2(data);
	if (keysym == XK_Escape)
		ft_free(data);
	if (keysym == XK_w)
		move_up(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_a)
		move_left(data);
	if (keysym == XK_d)
		move_right(data);
	door(data);
	if (data->map[data->y][data->x] == 'C')
	{
		data->map[data->y][data->x] = '0';
		data->item_nbr--;
	}
	if ((keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d))
		show_mouvement(data);
	return (0);
}

static t_data	*get_size(t_data *data, char *argv)
{
	int		fd;

	fd = 0;
	data->height = count_line(argv) * GRAPHIC_HEIGHT;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		map_error();
	}
	data->width = ft_strlen(data->map[0]) * GRAPHIC_WIDTH - 64;
	close(fd);
	return (data);
}

void	open_map(char *argv, t_data *data)
{
	data->mouv = 0;
	data->timer = 0;
	data->mouv_str = ft_itoa(data->mouv);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	data = get_texture(data);
	data = get_size(data, argv);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"So_Long");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		window_error();
	}
	show_map(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 32, COLOR, "Mouvement : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 68, 32, COLOR,
		data->mouv_str);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, ft_free, data);
	mlx_loop_hook(data->mlx_ptr, animated_sprite, data);
	mlx_loop(data->mlx_ptr);
}
