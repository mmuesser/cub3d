/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:07:26 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/22 15:35:04 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	max_len(char **map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			;
		if (j > max)
			max = j;
	}
	return (max);
}

int	len_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

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
		
	}
	map_cpy[i] = NULL;
	free_tab(map);
	return (map_cpy);
}

int	check_map(char **map)
{
	map = cpy_map()
}
