/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:56 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 14:31:00 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		loop;
	int		enemy_sprite;
	void	*mlx;
	void	*win;
	void	*img_enemy;
	void	*img_exit;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_collection;
	char	**map;
}	t_game;

/*----------------game setup-------------------*/

int		ft_exit_game(t_game *game);
void	ft_display_moves(t_game *game);
void	ft_gameplay(t_game *game);
void	ft_col_num(t_game *game);
void	ft_game_load(t_game *game);

/*--------------------map----------------------*/

int		ft_map_checker(t_game *game);
char	**map_reader(char *path);
void	ft_free(char **map);

/*------------------draw-----------------------*/

int		ft_map_draw(t_game *game);
int		ft_animation(t_game *game);
void	ft_img_draw(t_game *game, void *image, int x, int y);
void	ft_death_draw(t_game *game);

/*--------------------moves--------------------*/

void	ft_move_w(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);
void	ft_move_a(t_game *game);

#endif
