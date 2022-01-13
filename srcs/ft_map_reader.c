/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:28:13 by naqua             #+#    #+#             */
/*   Updated: 2021/12/09 21:09:30 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

char	**map_reader(char *path)
{
	int		fd;
	char	*temp;
	char	*map_holder;
	char	*line;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map_holder;
		map_holder = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	map = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (map);
}
