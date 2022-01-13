/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:58:28 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 13:56:21 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_key_moves(int keycode, t_game *game)
{
	if (keycode == 13)
	{
		game->y_player -= 1;
		ft_move_w(game);
	}
	else if (keycode == 1)
	{
		game->y_player += 1;
		ft_move_s(game);
	}
	else if (keycode == 2)
	{
		game->x_player += 1;
		ft_move_d(game);
	}
	else if (keycode == 0)
	{
		game->x_player -= 1;
		ft_move_a(game);
	}
}

static int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	else if (!game->endgame)
		ft_key_moves(keycode, game);
	return (0);
}

void	ft_gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 0, ft_key_press, game);
	mlx_hook(game->win, 17, 0, ft_exit_game, game);
	mlx_loop_hook(game->mlx, ft_animation, game);
}
