/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:02 by abouchik          #+#    #+#             */
/*   Updated: 2025/03/25 05:48:52 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		err("Usage: ./so_long <map_file.ber>");
	if (!check_file_extension(argv[1]))
		err("Invalid file extension. Map file must end with .ber");
	if (!parse_map(&map, argv[1]))
		err("Failed to parse map");
	if (!validate_map(&map))
	{
		free_map(&map);
		err("Invalid map");
	}
	free_map(&map);
	return (0);
}
