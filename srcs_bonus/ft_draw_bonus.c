/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:36:01 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 15:52:17 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

static void	ft_player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	ft_img_draw(game, image, x, y);
}

static void	ft_exit_draw(t_game *game, int x, int y)
{
	if (game->p_collection == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"assets/resources/exit.xpm", &game->img_w, &game->img_h);
	}
	ft_img_draw(game, game->img_exit, x, y);
}

int	ft_map_draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				ft_img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				ft_img_draw(game, game->img_background, x, y);
			else if (game->map[y][x] == 'C')
				ft_img_draw(game, game->img_collection, x, y);
			else if (game->map[y][x] == 'P')
				ft_player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				ft_exit_draw(game, x, y);
			else if (game->map[y][x] == 'K')
				ft_img_draw(game, game->img_enemy, x, y);
		}
	}
	ft_display_moves(game);
	return (0);
}

void	ft_death_draw(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_clear_window(game->mlx, game->win);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/resources/death.xpm", &game->img_w, &game->img_h);
	game->endgame = 1;
	ft_map_draw(game);
}
