/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:17:00 by pineau            #+#    #+#             */
/*   Updated: 2023/11/20 17:32:40 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_player(t_data *data)
// {
// 	data->player->x = 300;
// 	data->player->y = 300;
// 	data->player->size = 15;
// 	data->player->color = 0x008000;
// 	data->player->a = PI;
// 	data->player->dx = cos(data->player->a) * 10;
// 	data->player->dy = sin(data->player->a) * 10;
// }

int	init_data(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data);
		return (0);
	}
	// data->player = malloc(sizeof(t_player));
	// if (!data->player)
	// {
	// 	free(data);
	// 	return (0);
	// }
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		return (0);
	}
	init_map(data);
	return (1);
}

void	init_map(t_data *data)
{
	// data->map->mapx = 0;
	// data->map->mapy = 0;
	data->map->maps = 50;
	data->map->map = NULL;
	data->map->desc = NULL;
	// tab_maker(data);
	// int i = -1;
	// while (data->map->map[++i])
	// 	printf("ligne %d : %s\n", i, data->map->map[i]);
}
