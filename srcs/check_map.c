/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:07:26 by mmuesser          #+#    #+#             */
/*   Updated: 2023/12/14 13:41:05 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**cpy_map(char **map)
{
	char	**map_cpy;
	int		i;

	map_cpy = (char **) malloc(sizeof(char *) * (len_tab(map) + 1));
	if (!map_cpy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		map_cpy[i] = (char *) malloc(sizeof(char) * (max_len(map) + 1));
		if (!map_cpy[i])
			return (free_tab(map_cpy), NULL);
		fill_line(&map_cpy[i], map[i], max_len(map));
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	check_bordure(char **map, int i, int y)
{
	i = -1;
	while (map[++i])
	{
		y = -1;
		if (i == 0 || i == len_tab(map) - 1)
		{
			while (map[i][++y])
			{
				if (map[i][y] != '1' && map[i][y] != ' ')
					return (1);
			}
			continue ;
		}
		while (map[i][++y] == ' ')
			;
		if (map[i][y] != '1' && y != ft_strlen(map[i]))
			return (1);
		y = ft_strlen(map[i]);
		while (map[i][--y] == ' ' && y != 0)
			;
		if (map[i][y] != '1' && y != 0)
			return (1);
	}
	return (0);
}

int	check_espace(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == ' ')
			{
				if (i > 0 && (map[i - 1][y] != ' ' && map[i - 1][y] != '1'))
					return (1);
				if (i < len_tab(map) - 1 && (map[i + 1][y] != ' '
					&& map[i + 1][y] != '1'))
					return (1);
				if (y > 0 && (map[i][y - 1] != ' ' && map[i][y - 1] != '1'))
					return (1);
				if (y < ft_strlen(map[i]) - 1 && (map[i][y + 1] != ' '
					&& map[i][y + 1] != '1'))
					return (1);
			}
		}
	}
	return (0);
}

int	check_pos(char **map)
{
	int	i;
	int	y;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] != '1' && map[i][y] != '0' && map[i][y] != ' '
				&& map[i][y] != 'N' && map[i][y] != 'S' && map[i][y] != 'W'
				&& map[i][y] != 'E')
				return (1);
			if (map[i][y] == 'N' || map[i][y] == 'S' || map[i][y] == 'W'
				|| map[i][y] == 'E')
				count++;
		}
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_map(char **map)
{
	char	**map_cpy;

	map_cpy = cpy_map(map);
	if (!map_cpy)
		return (1);
	if (check_bordure(map_cpy, 0, 0) == 1)
		return (free_tab(map_cpy), 1);
	if (check_espace(map_cpy) == 1)
		return (free_tab(map_cpy), 1);
	if (check_pos(map_cpy) == 1)
		return (free_tab(map_cpy), 1);
	free_tab(map_cpy);
	return (0);
}
