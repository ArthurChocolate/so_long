/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:42:52 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 13:45:48 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_form_checker(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_wall_checker(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_symbol_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_presence(t_game *game)
{
	int	i;
	int	j;

	game->p_player = 0;
	game->p_collection = 0;
	game->p_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_player++;
			else if (game->map[i][j] == 'E')
				game->p_exit++;
			else if (game->map[i][j] == 'C')
				game->p_collection++;
			j++;
		}
		i++;
	}
	if (game->p_player != 1 || game->p_exit == 0 || game->p_collection == 0)
		return (0);
	return (1);
}

int	ft_map_checker(t_game *game)
{
	if (ft_form_checker(game->map) && ft_wall_checker(game->map)
		&& ft_symbol_checker(game->map) && ft_presence(game))
		return (1);
	return (0);
}
