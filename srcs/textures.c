/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:34:19 by pineau            #+#    #+#             */
/*   Updated: 2024/01/08 17:18:37 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	data->no->texture = mlx_xpm_file_to_image(data->mlx, data->no->path,
			&data->no->width, &data->no->height);
	if (!data->no->texture)
		return (end(data), exit(0));
	data->so->texture = mlx_xpm_file_to_image(data->mlx, data->so->path,
			&data->so->width, &data->so->height);
	if (!data->so->texture)
		return (end(data), exit(0));
	data->we->texture = mlx_xpm_file_to_image(data->mlx, data->we->path,
			&data->we->width, &data->we->height);
	if (!data->we->texture)
		return (end(data), exit(0));
	data->ea->texture = mlx_xpm_file_to_image(data->mlx, data->ea->path,
			&data->ea->width, &data->ea->height);
	if (!data->ea->texture)
		return (end(data), exit(0));
}

void	which_sprite(t_data *data, double len, double start)
{
	double	ray;

	if (data->player->endy != (double)(int)data->player->endy)
	{
		ray = data->player->endy;
		if (data->player->endx > data->player->x)
			print_east(data, len, start, ray);
		else
			print_west(data, len, start, ray);
	}
	if (data->player->endx != (double)(int)data->player->endx)
	{
		ray = data->player->endx;
		if (data->player->endy > data->player->y)
			print_south(data, len, start, ray);
		else
			print_north(data, len, start, ray);
	}
}
