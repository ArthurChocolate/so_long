/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:48:41 by naqua             #+#    #+#             */
/*   Updated: 2021/12/14 13:45:57 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_argc_num_checker(int argc)
{
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(1);
	}
}

static int	ft_argv_checker(char *argv)
{
	int	len;
	int	fd;

	len = 0;
	while (argv[len])
		len++;
	if (argv[len - 1] != 'r' || argv[len - 2] != 'e' || argv[len - 3] != 'b'
		|| argv[len - 4] != '.')
	{
		printf("Error\nWrong file format\n");
		exit(1);
		return (1);
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCannot read file or file does not exist\n");
		exit(1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_argc_num_checker(argc);
	ft_argv_checker(argv[1]);
	game.map = map_reader(argv[1]);
	ft_col_num(&game);
	if (ft_map_checker(&game) && !ft_argv_checker(argv[1]))
	{
		ft_game_load(&game);
		ft_gameplay(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		if (game.map)
			ft_free(game.map);
		printf("Error\nWrong map\n");
		exit(1);
	}	
	return (0);
}
