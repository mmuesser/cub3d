/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:45:57 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 14:06:36 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_down(t_data *data)
{
	double	new_x;
	double	new_y;

	data->player->x *= data->map->maps;
	data->player->y *= data->map->maps;
	data->player->x -= data->player->dx * 2;
	data->player->y -= data->player->dy * 2;
	new_x = data->player->x;
	new_y = data->player->y;
	new_x /= data->map->maps;
	new_y /= data->map->maps;
	if (data->map->map[(int)new_y][(int)new_x] == '1'
		|| !data->map->map[(int)new_y][(int)new_x])
	{
		data->player->x += data->player->dx * 2;
		data->player->y += data->player->dy * 2;
		data->player->x /= data->map->maps;
		data->player->y /= data->map->maps;
		return ;
	}
	data->player->x /= data->map->maps;
	data->player->y /= data->map->maps;
	draw_all(data);
}

void	key_up(t_data *data)
{
	double	new_x;
	double	new_y;

	data->player->x *= data->map->maps;
	data->player->y *= data->map->maps;
	data->player->x += data->player->dx * 2;
	data->player->y += data->player->dy * 2;
	new_x = data->player->x;
	new_y = data->player->y;
	new_x /= data->map->maps;
	new_y /= data->map->maps;
	if (data->map->map[(int)new_y][(int)new_x] == '1'
		|| !data->map->map[(int)new_y][(int)new_x])
	{
		data->player->x -= data->player->dx * 2;
		data->player->y -= data->player->dy * 2;
		data->player->x /= data->map->maps;
		data->player->y /= data->map->maps;
		return ;
	}
	data->player->x /= data->map->maps;
	data->player->y /= data->map->maps;
	draw_all(data);
}

void	key_d(t_data *data)
{
	double	new_x;
	double	new_y;

	data->player->x *= data->map->maps;
	data->player->y *= data->map->maps;
	data->player->x -= data->player->dy * 2;
	data->player->y += data->player->dx * 2;
	new_x = data->player->x;
	new_y = data->player->y;
	new_x /= data->map->maps;
	new_y /= data->map->maps;
	if (data->map->map[(int)new_y][(int)new_x] == '1'
		|| !data->map->map[(int)new_y][(int)new_x])
	{
		data->player->x += data->player->dy * 2;
		data->player->y -= data->player->dx * 2;
		data->player->x /= data->map->maps;
		data->player->y /= data->map->maps;
		return ;
	}
	data->player->x /= data->map->maps;
	data->player->y /= data->map->maps;
	draw_all(data);
}

void	key_a(t_data *data)
{
	double	new_x;
	double	new_y;

	data->player->x *= data->map->maps;
	data->player->y *= data->map->maps;
	data->player->x += data->player->dy * 2;
	data->player->y -= data->player->dx * 2;
	new_x = data->player->x;
	new_y = data->player->y;
	new_x /= data->map->maps;
	new_y /= data->map->maps;
	if (data->map->map[(int)new_y][(int)new_x] == '1'
		|| !data->map->map[(int)new_y][(int)new_x])
	{
		data->player->x -= data->player->dy * 2;
		data->player->y += data->player->dx * 2;
		data->player->x /= data->map->maps;
		data->player->y /= data->map->maps;
		return ;
	}
	data->player->x /= data->map->maps;
	data->player->y /= data->map->maps;
	draw_all(data);
}

void	key_right(t_data *data)
{
	data->player->a += 0.05;
	if (data->player->a > 2 * M_PI)
		data->player->a -= 2 * M_PI;
	data->player->dx = cos(data->player->a) * 10;
	data->player->dy = sin(data->player->a) * 10;
	draw_all(data);
}
