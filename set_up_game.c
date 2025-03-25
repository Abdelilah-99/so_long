/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:37:28 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/25 15:40:17 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_step(t_map *map)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(map->grid[0]);
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i++]) != row_len)
			(free_map(map), map_error(map, "Map must be rectangular"));
	}
	map->height = i;
	map->width = row_len;
	analyze_map(map);
	check_walls(map);
	render_game(map);
}

void	load_img(t_map *map)
{
	map->img0 = mlx_xpm_file_to_image(map->mlx, "./textures/0.xpm",
			&(int){0}, &(int){0});
	map->img1 = mlx_xpm_file_to_image(map->mlx, "./textures/1.xpm",
			&(int){0}, &(int){0});
	map->img_c = mlx_xpm_file_to_image(map->mlx, "./textures/C.xpm",
			&(int){0}, &(int){0});
	map->img_e = mlx_xpm_file_to_image(map->mlx, "./textures/E.xpm",
			&(int){0}, &(int){0});
	map->img_p = mlx_xpm_file_to_image(map->mlx, "./textures/P.xpm",
			&(int){0}, &(int){0});
	if (!map->img0 || !map->img1 || !map->img_c || !map->img_e || !map->img_p)
	{
		free_map(map);
		err("Failed to load images");
	}
}

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free_map(map);
		err("Failed to init mlx");
	}
	map->win = mlx_new_window(map->mlx, map->width * 32,
			map->height * 32, "abouchik");
	if (!map->win)
	{
		free_map(map);
		err("Failed to create window");
	}
}

void	render_tile(t_map *map, int j, int k)
{
	if (map->grid[k][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img0, j * 32, k * 32);
	else if (map->grid[k][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img1, j * 32, k * 32);
	else if (map->grid[k][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img_c, j * 32, k * 32);
	else if (map->grid[k][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img_p, j * 32, k * 32);
	else if (map->grid[k][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->img_e, j * 32, k * 32);
}

void	make_your_game(t_map *map)
{
	int	k;
	int	j;

	k = 0;
	while (k < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			render_tile(map, j, k);
			j++;
		}
		k++;
	}
}
