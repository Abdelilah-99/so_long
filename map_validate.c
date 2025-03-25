/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:20 by abouchik          #+#    #+#             */
/*   Updated: 2025/03/25 15:09:24 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **temp_map, int x, int y, int *count)
{
	if (x < 0 || y < 0 || temp_map[y] == NULL || temp_map[y][x] == '\0'
		|| temp_map[y][x] == '1' || temp_map[y][x] == 'V')
		return ;
	if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E')
		(*count)++;
	temp_map[y][x] = 'V';
	flood_fill(temp_map, x + 1, y, count);
	flood_fill(temp_map, x - 1, y, count);
	flood_fill(temp_map, x, y + 1, count);
	flood_fill(temp_map, x, y - 1, count);
}

char	**lets_make_a_map(t_map *map, char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		temp_map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!temp_map[i])
		{
			while (i >= 0)
				free(temp_map[i--]);
			free(temp_map);
			return (NULL);
		}
		j = 0;
		while (j < map->width)
		{
			temp_map[i][j] = map->grid[i][j];
			j++;
		}
		temp_map[i][j] = '\0';
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

int	check_path(t_map *map)
{
	char	**temp_map;
	int		count;
	int		i;
	int		total;

	temp_map = malloc(sizeof(char *) * (map->height + 1));
	if (!temp_map)
		return (0);
	temp_map = lets_make_a_map(map, temp_map);
	total = map->collectibles + 1;
	count = 0;
	flood_fill(temp_map, map->player_pos.x, map->player_pos.y, &count);
	i = 0;
	while (temp_map[i])
		(free(temp_map[i]), i++);
	free(temp_map);
	return (count == total);
}

int	validate_map(t_map *map)
{
	if (map->width < 3 || map->height < 3)
	{
		err("Map is too small");
		return (0);
	}
	if (!check_path(map))
	{
		free_map(map);
		err("No valid path to collect all collectibles and reach the exit");
		return (0);
	}
	return (1);
}
