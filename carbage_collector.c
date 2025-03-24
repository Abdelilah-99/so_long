/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:47:58 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/24 14:48:12 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_error(t_map *map, char *message)
{
    free_map(map);
    error_msg(message);
}

void free_map(t_map *map)
{
    int i;

    if (!map->grid)
        return;
    i = 0;
    while (map->grid[i])
        free(map->grid[i++]);
    free(map->grid);
    map->grid = NULL;
}