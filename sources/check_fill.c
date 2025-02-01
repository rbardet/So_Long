/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 07:46:19 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 03:04:18 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_base(char *str)
{
	char	*base;
	int		a;
	int		b;

	base = "01CEPD";
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '\n')
			break ;
		b = 0;
		while (base[b] != '\0')
		{
			if (str[a] == base[b])
				break ;
			b++;
		}
		if (base [b] == '\0')
		{
			ft_printf("%s", str);
			return (1);
		}
		a++;
	}
	return (0);
}

int	check_fill(char *argv)
{
	char	*str;
	int		b;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		b = check_base(str);
		if (b == 1)
		{
			free(str);
			return (1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
