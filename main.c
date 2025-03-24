/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:32:27 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/24 14:32:30 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *message)
{
	printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		error_msg("Usage: ./so_long <map_file.ber>");
	if (!check_file_extension(argv[1]))
		error_msg("Invalid file extension. Map file must end with .ber");
	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	map.collectibles = 0;
	map.exits = 0;
	map.players = 0;
	if (!parse_map(&map, argv[1]))
		error_msg("Failed to parse map");
	if (!validate_map(&map))
	{
		free_map(&map);
		error_msg("Invalid map");
	}
	printf("Map successfully parsed and validated!\n");
	printf("Map size: %d x %d\n", map.width, map.height);
	printf("Player position: (%d, %d)\n", map.player_pos.x, map.player_pos.y);
	printf("Collectibles: %d\n", map.collectibles);
	free_map(&map);
	return (0);
}