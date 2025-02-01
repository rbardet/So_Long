/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:07:22 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:44:25 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	check_extension(char *argv, int len)
{
	if (argv[len - 1] != 'r')
	{
		ft_printf("Error\nLe fichier de map n'est pas un fichier .ber.");
		exit(EXIT_FAILURE);
	}
	if (argv[len - 2] != 'e')
	{
		ft_printf("Error\nLe fichier de map n'est pas un fichier .ber.");
		exit(EXIT_FAILURE);
	}
	if (argv[len - 3] != 'b')
	{
		ft_printf("Error\nLe fichier de map n'est pas un fichier .ber.");
		exit(EXIT_FAILURE);
	}
	if (argv[len - 4] != '.')
	{
		ft_printf("Error\nLe fichier de map n'est pas un fichier .ber.");
		exit(EXIT_FAILURE);
	}
}

int	so_long(int nbline, char *argv)
{
	int		check;
	t_data	data;

	data.x = 0;
	data.y = 0;
	check = check_map(nbline, argv);
	if (check != 0)
		map_error();
	data.map = map_reader(argv);
	while (data.map[data.y][data.x] != 'P')
	{
		if (data.map[data.y][data.x] == '\n')
		{
			data.y++;
			data.x = 0;
		}
		data.x++;
	}
	data.item_nbr = get_item_nbr(data.map);
	flood_fill(data.x, data.y, data.map);
	check_path(data.map);
	free_map(data.map);
	data.map = remap_reader(argv);
	open_map(argv, &data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		nbline;
	int		a;

	if (argc != 2)
	{
		ft_printf("Error\nAucune map passer en parametre.");
		return (1);
	}
	a = ft_strlen(argv[1]);
	check_extension(argv[1], a);
	nbline = count_line(argv[1]);
	if (nbline < 3)
		map_error();
	so_long(nbline, argv[1]);
	return (0);
}
