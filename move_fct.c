/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:38:15 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/25 15:11:16 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, int x, int y, char replace_with)
{
	map->grid[map->player_pos.y][map->player_pos.x] = replace_with;
	map->player_pos.x += x;
	map->player_pos.y += y;
	map->grid[map->player_pos.y][map->player_pos.x] = 'P';
}

void	handle_exit_movement(t_map *map, int x, int y)
{
	move_player(map, x, y, '0');
	map->on_exit = 1;
	if (map->collectibles == 0)
		ft_winner(map);
}

void	applied_mov(t_map *map, int x, int y)
{
	if (map->grid[map->player_pos.y + y][map->player_pos.x + x] == '1')
		return ;
	else if (map->on_exit == 1
		&& map->grid[map->player_pos.y + y][map->player_pos.x + x] != '1')
	{
		move_player(map, x, y, 'E');
		map->on_exit = 0;
	}
	else if (map->grid[map->player_pos.y + y][map->player_pos.x + x] == '0')
		move_player(map, x, y, '0');
	else if (map->grid[map->player_pos.y + y][map->player_pos.x + x] == 'C')
	{
		map->collectibles--;
		move_player(map, x, y, '0');
	}
	else if (map->grid[map->player_pos.y + y][map->player_pos.x + x] == 'E')
		handle_exit_movement(map, x, y);
	map->c++;
	ft_putstr_fd("MOVE: ", 1);
	ft_putnbr_fd(map->c, 1);
	ft_putstr_fd("\n", 1);
	make_your_game(map);
}
