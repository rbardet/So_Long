/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:35:14 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:18:04 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

void	free_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

int	ft_free(t_data *data)
{
	free_tab(data->map);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->item)
		mlx_destroy_image(data->mlx_ptr, data->item);
	if (data->player)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->player2)
		mlx_destroy_image(data->mlx_ptr, data->player2);
	if (data->player3)
		mlx_destroy_image(data->mlx_ptr, data->player3);
	if (data->enemy)
		mlx_destroy_image(data->mlx_ptr, data->enemy);
	if (data->enemy2)
		mlx_destroy_image(data->mlx_ptr, data->enemy2);
	free(data->mouv_str);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
