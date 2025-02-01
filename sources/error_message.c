/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:37 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 01:03:27 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	map_error(void)
{
	ft_printf("Error\nLa map n'est pas conforme.");
	exit(EXIT_FAILURE);
}

void	texture_error(void)
{
	ft_printf("Error\nLes textures n'ont pas pu etre creer.");
	exit(EXIT_FAILURE);
}

void	window_error(void)
{
	ft_printf("Error\nProbleme d'assignation.");
	exit(EXIT_FAILURE);
}

void	size_error(void)
{
	ft_printf("Error\nLa map est trop grande.");
	exit(EXIT_FAILURE);
}

void	form_error(void)
{
	ft_printf("Error\nLa map n'est pas rectangulaire.");
	exit(EXIT_FAILURE);
}
