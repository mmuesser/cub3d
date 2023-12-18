/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:03:28 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 15:40:12 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data);
		return (0);
	}
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		free(data->img);
		free(data);
		return (0);
	}
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data->img);
		free(data->player);
		free(data);
		return (0);
	}
	data->map->desc = NULL;
	data->map->map = NULL;
	return (1);
}

int	init_images(t_data *data)
{
	data->no = malloc(sizeof(t_img));
	if (!data->no)
	{
		free_img(data);
		return (0);
	}
	data->so = malloc(sizeof(t_img));
	if (!data->so)
	{
		free_img(data);
		return (0);
	}
	data->we = malloc(sizeof(t_img));
	if (!data->we)
	{
		free_img(data);
		return (0);
	}
	data->ea = malloc(sizeof(t_img));
	if (!data->ea)
	{
		free_img(data);
		return (0);
	}
	return (1);
}
