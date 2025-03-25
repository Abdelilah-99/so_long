/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carbage_collector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:13:58 by abouchik          #+#    #+#             */
/*   Updated: 2025/03/25 05:47:02 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx_resources(t_map *map)
{
	if (map->mlx)
	{
		if (map->img0)
			mlx_destroy_image(map->mlx, map->img0);
		if (map->img1)
			mlx_destroy_image(map->mlx, map->img1);
		if (map->img_c)
			mlx_destroy_image(map->mlx, map->img_c);
		if (map->img_e)
			mlx_destroy_image(map->mlx, map->img_e);
		if (map->img_p)
			mlx_destroy_image(map->mlx, map->img_p);
		if (map->win)
		{
			mlx_clear_window(map->mlx, map->win);
			mlx_destroy_window(map->mlx, map->win);
		}
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

void	map_error(t_map *map, char *message)
{
	free_map(map);
	err(message);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
		free(map->grid[i++]);
	free_mlx_resources(map);
	free(map->grid);
	map->grid = NULL;
}
