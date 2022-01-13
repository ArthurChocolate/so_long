/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:59:56 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 14:13:21 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_player_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/resources/player_right.xpm", &game->img_w,
				&game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/resources/player_left.xpm", &game->img_w,
				&game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/resources/player_right.xpm", &game->img_w,
				&game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/resources/player_left.xpm", &game->img_w,
				&game->img_h);
}

void	ft_move_w(t_game *game)
{
	ft_player_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->p_collection == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else if (game->map[game->y_player][game->x_player] == 'K')
		ft_death_draw(game);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->p_collection -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	ft_move_s(t_game *game)
{
	ft_player_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->p_collection == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else if (game->map[game->y_player][game->x_player] == 'K')
		ft_death_draw(game);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->p_collection -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	ft_move_d(t_game *game)
{
	ft_player_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->p_collection == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else if (game->map[game->y_player][game->x_player] == 'K')
		ft_death_draw(game);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->p_collection -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	ft_move_a(t_game *game)
{
	ft_player_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->p_collection == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else if (game->map[game->y_player][game->x_player] == 'K')
		ft_death_draw(game);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->p_collection -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}
