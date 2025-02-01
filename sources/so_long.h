/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:59:55 by rbardet-          #+#    #+#             */
/*   Updated: 2025/01/31 04:28:59 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "../LIBFT_V2/libft.h"
# include "../minilibx-linux/mlx.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define GRAPHIC_WIDTH 64
# define GRAPHIC_HEIGHT 64

# define INT_MAX 2147483647
# define COLOR 0xFF0000

typedef struct s_data
{
	void	*mlx_ptr;
	int		width;
	int		height;
	void	*win_ptr;
	char	**map;
	int		x;
	int		y;
	int		item_nbr;
	void	*wall;
	void	*floor;
	void	*player;
	void	*player2;
	void	*player3;
	void	*item;
	void	*exit;
	void	*enemy;
	void	*enemy2;
	int		mouv;
	char	*mouv_str;
	int		timer;
}	t_data;

int		check_corner(int nbline, char *argv);
int		count_line(char *argv);
int		check_content(int fd);
int		check_fill(char *argv);
int		check_map(int nbline, char *argv);
int		check_mapsize(char **map);
int		check_mapform(char **map);
void	flood_fill(int x, int y, char **map);
void	check_path(char **map);
char	**remap_reader(char *argv);
void	free_map(char **map);
char	**map_reader(char *argv);
void	open_map(char *argv, t_data *data);
void	show_map2(t_data *data);
void	map_error(void);
void	texture_error(void);
void	window_error(void);
void	size_error(void);
void	form_error(void);
void	path_error(void);
int		ft_free(t_data *data);
int		width(char *argv);
void	check_type(char **map, t_data *data, int x, int y);
void	check_type2(char **map, t_data *data, int x, int y);
void	check_type3(char **map, t_data *data, int x, int y);
t_data	*get_texture(t_data *data);
int		get_item_nbr(char **map);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	door(t_data *data);
void	move_up2(t_data *data);
void	move_down2(t_data *data);
void	move_left2(t_data *data);
void	move_right2(t_data *data);
void	free_tab(char **tab);
int		animated_sprite(t_data *data);

#endif
