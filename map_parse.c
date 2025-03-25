/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:08 by abouchik          #+#    #+#             */
/*   Updated: 2025/03/25 15:49:22 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_element(t_map *map, char element, int x, int y)
{
	if (element == 'C')
		map->collectibles++;
	else if (element == 'E')
	{
		map->exits++;
		if (map->exits > 1)
			map_error(map, "Map must contain exactly 1 exit (E)");
	}
	else if (element == 'P')
	{
		map->players++;
		if (map->players > 1)
			map_error(map, "Map must contain exactly 1 player (P)");
		map->player_pos.x = x;
		map->player_pos.y = y;
	}
	else if (element != '0' && element != '1')
		map_error(map, "Invalid character in map");
}

void	analyze_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			count_element(map, map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	if (map->collectibles < 1)
		map_error(map, "Map must contain at least 1 collectible (C)");
	if (map->exits != 1)
		map_error(map, "Map must contain exactly 1 exit (E)");
	if (map->players != 1)
		map_error(map, "Map must contain exactly 1 player (P)");
}

void	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((y == 0 || y == map->height - 1
					|| x == 0 || x == map->width - 1)
				&& map->grid[y][x] != '1')
				map_error(map, "Map must be surrounded by walls");
			x++;
		}
		y++;
	}
}

int	init_data(t_map *map)
{
	if (!map)
		return (0);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->img0 = NULL;
	map->img1 = NULL;
	map->img_e = NULL;
	map->img_c = NULL;
	map->img_p = NULL;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->c = 0;
	map->on_exit = 0;
	return (1);
}

int	parse_map(t_map *map, char *filename)
{
	char	*map_str;

	if (!init_data(map))
		return (0);
	map_str = read_entire_file(filename);
	if (!map_str || map_str[0] == '\0')
		(free(map_str), map_error(map, "Map err"));
	map->grid = ft_split(map_str, '\n');
	free(map_str);
	if (!map->grid)
		return (err("Error init grid"), 0);
	first_step(map);
	return (1);
}
