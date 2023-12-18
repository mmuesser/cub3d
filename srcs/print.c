/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:23:10 by pineau            #+#    #+#             */
/*   Updated: 2023/12/12 17:36:58 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_backgroud(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->maps / 10)
	{
		j = 0;
		while (j < data->map->maps / 10)
		{
			put_pixel(data->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player->x * data->map->maps / 10;
	y = data->player->y * data->map->maps / 10;
	draw_square(data, x, y, 0xFF0000);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;
	int	x_square;
	int	y_square;

	y = 0;
	while (data->map->map[y])
	{
		y_square = y * data->map->maps / 10;
		x = 0;
		while (data->map->map[y][x])
		{
			x_square = x * data->map->maps / 10;
			if (data->map->map[y][x] == '1')
				draw_square(data, x_square, y_square, 0x008000);
			else if (data->map->map[y][x] == '0')
				draw_square(data, x_square, y_square, 0xFFFFFF);
			else if (data->map->map[y][x] == 'N' || data->map->map[y][x] == 'S'
				|| data->map->map[y][x] == 'W' || data->map->map[y][x] == 'E')
				draw_square(data, x_square, y_square, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_grid(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x % data->map->maps == 0 || y % data->map->maps == 0)
				put_pixel(data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
