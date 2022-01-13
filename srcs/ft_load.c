/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:56:46 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 14:47:35 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_img(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image
		(game->mlx, "assets/resources/background.xpm", &game->img_w,
			&game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/resources/wall.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/resources/player_right.xpm", &game->img_w,
			&game->img_h);
	game->img_collection = mlx_xpm_file_to_image
		(game->mlx, "assets/resources/collection.xpm", &game->img_w,
			&game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/resources/exit.xpm", &game->img_w, &game->img_h);
}

static void	ft_window_size(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
}

void	ft_game_load(t_game *game)
{
	game->mlx = mlx_init();
	ft_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	ft_img(game);
	ft_map_draw(game);
}
