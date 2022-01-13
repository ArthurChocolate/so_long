/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:22:47 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 15:51:57 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->enemy_sprite == 1)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, "assets/resources/e1.xpm", &game->img_w, &game->img_h);
	else if (game->enemy_sprite == 2)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, "assets/resources/e2.xpm", &game->img_w, &game->img_h);
	else if (game->enemy_sprite == 3)
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, "assets/resources/e3.xpm", &game->img_w, &game->img_h);
	else if (game->enemy_sprite == 4)
	{
		game->img_enemy = mlx_xpm_file_to_image
			(game->mlx, "assets/resources/e4.xpm", &game->img_w, &game->img_h);
		game->enemy_sprite = 1;
	}
	ft_map_draw(game);
	game->enemy_sprite++;
	return (0);
}
