/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:29:21 by naqua             #+#    #+#             */
/*   Updated: 2021/12/10 14:51:41 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	int		p_player;
	int		p_collection;
	int		p_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	void	*mlx;
	void	*win;
	void	*img_exit;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_collection;
	char	**map;
}	t_game;

/*----------------game setup-------------------*/

int		ft_exit_game(t_game *game);
void	ft_gameplay(t_game *game);

/*-----------------map/draw--------------------*/

int		ft_map_checker(t_game *game);
int		ft_map_draw(t_game *game);
char	**map_reader(char *path);
void	ft_free(char **map);
void	ft_game_load(t_game *game);
void	ft_img_draw(t_game *game, void *image, int x, int y);
void	ft_col_num(t_game *game);

/*--------------------moves--------------------*/

void	ft_move_w(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);
void	ft_move_a(t_game *game);

#endif
