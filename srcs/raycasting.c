/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:07:28 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 14:08:32 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	draw_rayx2(t_data *data)
{
	int		side;
	double	length;
	double	tmp;

	side = look(data, 1);
	length = data->player->xx - side;
	if (length == 0)
	{
		side = side -1;
		length = data->player->xx - side;
	}
	if (length < 0)
		length = length * (-1);
	tmp = length / cos(data->player->a);
	return (tmp);
}

double	draw_rayy2(t_data *data)
{
	int		side;
	double	length;
	double	tmp;

	side = look(data, 2);
	length = data->player->yy - side;
	if (length == 0)
	{
		side = side -1;
		length = data->player->yy - side;
	}
	if (length < 0)
		length = length * (-1);
	tmp = length / sin(data->player->a);
	return (tmp);
}

int	mode1_1(t_data *data, double tmpx, double tmpy)
{
	if (!(int)tmpy)
		return (1);
	if (data->map->map[(int)tmpy - 1][(int)tmpx] == '1'
		&& (data->player->a >= M_PI && data->player->a <= 2 * M_PI))
		return (1);
	if (data->map->map[(int)tmpy][(int)tmpx] == '1'
		&& (data->player->a <= M_PI && data->player->a >= 0))
		return (1);
	return (0);
}

int	mode2_2(t_data *data, double tmpx, double tmpy)
{
	if (!(int)tmpx)
		return (1);
	if (data->map->map[(int)tmpy][(int)tmpx - 1] == '1'
		&& (data->player->a >= M_PI / 2 && data->player->a <= 3 * M_PI / 2))
		return (1);
	if (data->map->map[(int)tmpy][(int)tmpx] == '1')
		return (1);
	return (0);
}

int	hit_wall2(t_data *data, double i, int mode)
{
	double	tmpx;
	double	tmpy;

	tmpy = data->player->yy + i * sin(data->player->a);
	tmpx = data->player->xx + i * cos(data->player->a);
	data->player->endx = tmpx;
	data->player->endy = tmpy;
	if (mode == 1)
	{
		if (mode1_1(data, tmpx, tmpy) == 1)
			return (1);
	}
	if (mode == 2)
	{
		if (mode2_2(data, tmpx, tmpy) == 1)
			return (1);
	}
	data->player->xx = tmpx;
	data->player->yy = tmpy;
	return (0);
}
