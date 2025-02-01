/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_corner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:33:19 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/05 02:32:06 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_topbot(int nbline, int fd)
{
	char	*str;
	int		a;

	a = 0;
	str = get_next_line(fd);
	if (!str)
		map_error();
	while (str[a] != '\0')
	{
		if (str[a] != '1' && str[a] != '\n')
		{
			free (str);
			map_error();
		}
		a++;
	}
	free (str);
	nbline--;
	return (nbline);
}

static int	check_side(int nbline, int fd)
{
	char	*str;
	int		b;

	str = get_next_line(fd);
	if (!str)
		map_error();
	b = ft_strlen(str) - 2;
	if (str[0] == '1' && str[b] == '1')
	{
		free (str);
		nbline--;
		return (nbline);
	}
	free(str);
	map_error();
	return (1);
}

int	check_corner(int nbline, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		map_error();
	}
	nbline = check_topbot(nbline, fd);
	while (nbline != 1)
		nbline = check_side(nbline, fd);
	nbline = check_topbot(nbline, fd);
	close(fd);
	return (0);
}
// int main(int argc, char **argv)
// {
// 	int nbline;
// 	if (argc != 2)
// 		return (1);
// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	nbline = count_line(argv[1]);
// 	if (nbline < 3)
// 		map_error();
// 	close(fd);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	printf("%d", check_corner(nbline, argv[1]));
// 	close(fd);
// 	return (0);
// }

// #include "so_long.h"
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>

// static void free_tab(char **str)
// {
// 	int a;

// 	a = 0;
// 	while (str[a] != NULL)
// 	{
// 		free(str[a]);
// 		a++;
// 	}
// 	map_error();
// }
// static int	check_topbot(char **str, int tab)
// {
// 	int		a;

// 	a = 0;
// 	while (str[tab][a] != '\0')
// 	{
// 		if (str[tab][a] != '1' && str[tab][a] != '\n')
// 			free_tab(str);
// 		a++;
// 	}
// 	tab++;
// 	return (tab);
// }

// static int	check_side(char **str, int tab)
// {
// 	int		b;

// 	b = ft_strlen(str[tab]) - 2;
// 	if (str[tab][0] == '1' && str[tab][b] == '1')
// 	{
// 		free (str);
// 		tab++;
// 		return (tab);
// 	}
// 	free_tab(str);
// 	return (1);
// }

// int	check_corner(int nbline, char *argv)
// {
// 	int tab;
// 	char **str;

// 	tab = 0;
// 	str = map_reader(argv);
// 	tab = check_topbot(str, tab);
// 	while (tab < nbline - 1)
// 		tab = check_side(str, tab);
// 	tab = check_topbot(str, tab);
// 	return (0);
// }
