/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:06:50 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 13:43:39 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_line2(t_data *data, double i, double j, int color)
{
	double	len;

	len = i;
	while (len < j)
	{
		put_pixel(data->img, data->player->nbr_ray, len, color);
		len++;
	}
}

void	print_line(t_data *data, double ray_length)
{
	double	len;
	double	start;

	len = ray_length;
	len *= cos(data->player->a - data->player->tmpa);
	len = (HEIGHT / len);
	start = (HEIGHT - len) / 2;
	if (len <= HEIGHT)
	{
		print_line2(data, 0, start, data->map->ceiling);
		which_sprite(data, len, start);
		print_line2(data, start + len, HEIGHT, data->map->floor);
	}
	else
	{
		which_sprite(data, len, start);
	}
}

void	test_3d(t_data *data)
{
	double	ray_length;

	if (data->player->endx == 0)
		data->player->endx = 1;
	if (data->player->endy == 0)
		data->player->endy = 1;
	ray_length = sqrt((data->player->endx - data->player->x)
			* (data->player->endx - data->player->x)
			+ (data->player->endy - data->player->y)
			* (data->player->endy - data->player->y));
	data->player->distance = ray_length;
	print_line(data, ray_length);
}
