/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:05:43 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 14:31:33 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_display_moves(t_game *game)
{
	char	*str;
	char	*lose;
	int		x;
	int		y;
	int		i;

	i = game->map_h / 2;
	x = game->map_w / 2;
	y = game->map_h - 12;
	str = ft_itoa(game->moves);
	if (game->endgame)
	{
		mlx_string_put(game->mlx, game->win, x, i, 0xFF0000, "GAME OVER");
		mlx_string_put(game->mlx, game->win, x - 50, i + 32, 0xFF0000,
			"please press ESC to exit");
	}
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, x + 42, y, 0xFFFFFF, str);
	free(str);
}
