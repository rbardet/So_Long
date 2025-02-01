/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:28:18 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 01:04:49 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	checker(int c, int e, int p, int fd)
{
	char	*str;
	int		a;

	str = get_next_line(fd);
	while (str != NULL)
	{
		a = 0;
		while (str[a] != '\0')
		{
			if (str[a] == 'C')
				c++;
			else if (str[a] == 'E')
				e++;
			else if (str[a] == 'P')
				p++;
			a++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (e == 1 && c > 0 && p == 1)
		return (0);
	else
		return (1);
}

int	check_content(int fd)
{
	int		c;
	int		e;
	int		p;

	c = 0;
	e = 0;
	p = 0;
	return (checker(c, e, p, fd));
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	printf("%d", check_content(fd));
// 	close(fd);
// 	return (0);
// }
