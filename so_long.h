/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:32:45 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/24 14:49:09 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
typedef struct s_position
{
	int x;
	int y;
} t_position;

typedef struct s_map
{
	char **grid;
	int width;
	int height;
	int collectibles;
	int exits;
	int players;
	t_position player_pos;
} t_map;

/* Map parsing and validation */
int parse_map(t_map *map, char *filename);
int validate_map(t_map *map);
int check_path(t_map *map);
void free_map(t_map *map);

/* Map reading */
char *read_entire_file(char *filename);
char *reading(char *content, char *buffer, int fd, int bytes_read);

/* Error handling */
void error_msg(char *message);
int check_file_extension(char *filename);

/* Carbage collector */
void map_error(t_map *map, char *message);
void free_map(t_map *map);

/* Utils */
char *ft_strjoin(char *s1, char *s2);
char **ft_split(char const *s, char c);
int ft_strlen(const char *s);

#endif