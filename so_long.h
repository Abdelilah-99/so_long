/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:25 by abouchik          #+#    #+#             */
/*   Updated: 2025/03/25 15:40:58 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	void		*img0;
	void		*img1;
	void		*img_p;
	void		*img_e;
	void		*img_c;
	char		**grid;
	int			c;
	int			width;
	int			height;
	int			collectibles;
	int			exits;
	int			players;
	int			on_exit;
	t_position	player_pos;
}	t_map;

/* Map parsing and validation */
int		parse_map(t_map *map, char *filename);
int		validate_map(t_map *map);
int		check_path(t_map *map);
void	free_map(t_map *map);
void	check_walls(t_map *map);
void	analyze_map(t_map *map);

/* Map reading */
char	*read_entire_file(char *filename);
void	make_your_game(t_map *map);
void	load_img(t_map *map);
void	init_window(t_map *map);
void	first_step(t_map *map);
void	render_game(t_map *map);

/* Error handling */
void	err(char *msg);
int		check_file_extension(char *filename);

/* Printing */
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Carbage collector */
void	map_error(t_map *map, char *message);
void	free_map(t_map *map);

/* Movement */
void	applied_mov(t_map *map, int x, int y);
void	move_player(t_map *map, int x, int y, char replace_with);
void	handle_exit_movement(t_map *map, int x, int y);

/* Fin-game */
void	ft_winner(t_map *map);

/* Utils */
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
#endif