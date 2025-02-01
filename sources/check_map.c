/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:07:39 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/05 01:14:10 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	check_map(int nbline, char *argv)
{
	int	check;
	int	fd;

	check = check_corner(nbline, argv);
	if (check != 0)
		map_error();
	check = check_fill(argv);
	if (check != 0)
		map_error();
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	check = check_content(fd);
	close(fd);
	if (check != 0)
		map_error();
	return (0);
}
// int main(int argc, char **argv)
// {
// 	int	nbline;

// 	if (argc != 2)
// 		return (1);
// 	nbline = count_line(argv[1]);
// 	if (nbline < 3)
// 		map_error();
// 	check_map(nbline, argv[1]);
// 	return (0);
// }
