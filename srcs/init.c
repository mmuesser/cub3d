/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:17:00 by pineau            #+#    #+#             */
/*   Updated: 2023/12/18 11:46:08 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stddef.h>

void	orientation(char c, t_data *data)
{
	if (c == 'N')
		data->player->a = 3 * M_PI / 2;
	if (c == 'S')
		data->player->a = M_PI / 2.0001;
	if (c == 'W')
		data->player->a = M_PI;
	if (c == 'E')
		data->player->a = 1.9999 * M_PI;
}

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'N' || data->map->map[y][x] == 'S'
				|| data->map->map[y][x] == 'W' || data->map->map[y][x] == 'E')
			{
				orientation(data->map->map[y][x], data);
				data->player->x = x + 0.5;
				data->player->y = y + 0.5;
				return ;
			}
			++x;
		}
		++y;
	}
	return ;
}

void	find_path(t_data *data, int i, int j)
{
	if (data->map->desc[i][0] == 'N')
	{
		while (data->map->desc[i][j] == ' ')
			j++;
		data->so->path = ft_strdup(data->map->desc[i] + j);
	}
	if (data->map->desc[i][0] == 'S')
	{
		while (data->map->desc[i][j] == ' ')
			j++;
		data->no->path = ft_strdup(data->map->desc[i] + j);
	}
	if (data->map->desc[i][0] == 'W')
	{
		while (data->map->desc[i][j] == ' ')
			j++;
		data->ea->path = ft_strdup(data->map->desc[i] + j);
	}
	if (data->map->desc[i][0] == 'E')
	{
		while (data->map->desc[i][j] == ' ')
			j++;
		data->we->path = ft_strdup(data->map->desc[i] + j);
	}
}

void	fill_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (data->map->desc[i])
		find_path(data, i++, j);
	init_textures(data);
	find_rgb(data);
}

void	init_player(t_data *data)
{
	find_player(data);
	data->player->tmpa = 0;
	data->player->endx = 0;
	data->player->endy = 0;
	data->player->xx = data->player->x;
	data->player->yy = data->player->y;
	data->player->distance = 0.5;
	data->map->maps = 50;
	data->player->line = 0;
	data->player->size = 15;
	data->player->color = 0xFF0000;
	data->player->dx = cos(data->player->a) * 10;
	data->player->dy = sin(data->player->a) * 10;
}
