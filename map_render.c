/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:30:54 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/25 05:38:55 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_handler(t_map *map)
{
	free_map(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_winner(t_map *map)
{
	free_map(map);
	ft_putstr_fd("🎉 Congratulations! You won the game! 🎉\n", 1);
	exit(EXIT_SUCCESS);
}

void	handle_key(int key, t_map *map)
{
	if (key == KEY_ESC)
	{
		free_map(map);
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_UP)
		applied_mov(map, 0, -1);
	else if (key == KEY_DOWN)
		applied_mov(map, 0, 1);
	else if (key == KEY_LEFT)
		applied_mov(map, -1, 0);
	else if (key == KEY_RIGHT)
		applied_mov(map, 1, 0);
}

int	event_listner(int key, t_map *map)
{
	handle_key(key, map);
	return (0);
}

void	render_game(t_map *map)
{
	init_window(map);
	load_img(map);
	make_your_game(map);
	mlx_key_hook(map->win, event_listner, map);
	mlx_hook(map->win, 17, 0, exit_handler, map);
	mlx_loop(map->mlx);
}
