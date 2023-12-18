/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:10:13 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 14:10:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mode2(t_data *data, double tmpx, double tmpy)
{
	if (!(int)tmpx)
		return (1);
	if (data->map->map[(int)tmpy][(int)tmpx - 1] == '1'
		&& (data->player->a >= M_PI / 2 && data->player->a <= 3 * M_PI / 2))
	{
		data->player->endx = tmpx;
		data->player->endy = tmpy;
		test_3d(data);
		return (1);
	}
	if (data->map->map[(int)tmpy][(int)tmpx] == '1')
	{
		data->player->endx = tmpx;
		data->player->endy = tmpy;
		test_3d(data);
		return (1);
	}
	return (0);
}

int	hit_wall(t_data *data, double i, int mode)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player->x + i * cos(data->player->a);
	tmpy = data->player->y + i * sin(data->player->a);
	if (mode == 1)
	{
		if (mode1(data, tmpx, tmpy) == 1)
			return (1);
	}
	if (mode == 2)
	{
		if (mode2(data, tmpx, tmpy) == 1)
			return (1);
	}
	data->player->xx = tmpx;
	data->player->yy = tmpy;
	test_3d(data);
	return (0);
}

int	draw_ray(t_data *data)
{
	double	i;
	double	k;

	i = draw_rayx(data);
	k = draw_rayy(data);
	if (i < 0)
		i = i * (-1);
	if (k < 0)
		k = k * (-1);
	if (k < i)
	{
		data->player->side = 1;
		data->player->line += k;
		if (hit_wall(data, k, 1) == 1)
			return (data->player->line = 0, 1);
	}
	else
	{
		data->player->side = 2;
		data->player->line += i;
		if (hit_wall(data, i, 2) == 1)
			return (data->player->line = 0, 1);
	}
	return (data->player->line = 0, 0);
}
