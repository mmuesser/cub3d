/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:30:20 by pineau            #+#    #+#             */
/*   Updated: 2023/12/18 13:44:09 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mizalanorme(t_data *data, int j, double angle_offset, int ray_count)
{
	int	i;

	while (j < ray_count)
	{
		angle_offset = (double)j / (double)(ray_count - 1)
			*data->player->fov_radians - (data->player->fov_radians / 2.0);
		data->player->a = data->player->tmpa + angle_offset;
		if (data->player->a <= 0)
			data->player->a += 2 * M_PI;
		if (data->player->a > 2 * M_PI)
			data->player->a -= 2 * M_PI;
		data->player->xx = data->player->x;
		data->player->yy = data->player->y;
		i = 0;
		if (draw_ray(data) == 0)
		{
			while (i == 0)
			{
				if (draw_ray2(data) == 1)
					i = 1;
			}
		}
		data->player->nbr_ray++;
		j++;
	}
}

void	draw_all(t_data *data)
{
	int		ray_count;
	int		j;
	double	angle_offset;

	angle_offset = 0;
	data->player->fov_degrees = 90;
	ray_count = WIDTH;
	j = 0;
	data->player->nbr_ray = 0;
	data->player->tmpa = data->player->a;
	data->player->fov_radians = data->player->fov_degrees * M_PI / 180.0;
	mizalanorme(data, j, angle_offset, ray_count);
	data->player->a = data->player->tmpa;
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
}

double	draw_rayx(t_data *data)
{
	int		side;
	double	length;
	double	tmp;

	side = look(data, 1);
	length = data->player->x - side;
	if (length < 0)
		length = length * (-1);
	tmp = length / cos(data->player->a);
	return (tmp);
}

double	draw_rayy(t_data *data)
{
	int		side;
	double	length;
	double	tmp;

	side = look(data, 2);
	length = data->player->y - side;
	if (length < 0)
		length = length * (-1);
	tmp = length / sin(data->player->a);
	return (tmp);
}

int	mode1(t_data *data, double tmpx, double tmpy)
{
	if (!(int)tmpy)
		return (1);
	if (data->map->map[(int)tmpy - 1][(int)tmpx] == '1'
		&& (data->player->a >= M_PI && data->player->a <= 2 * M_PI))
	{
		data->player->endx = tmpx;
		data->player->endy = tmpy;
		test_3d(data);
		return (1);
	}
	if (data->map->map[(int)tmpy][(int)tmpx] == '1'
		&& (data->player->a <= M_PI && data->player->a >= 0))
	{
		data->player->endx = tmpx;
		data->player->endy = tmpy;
		test_3d(data);
		return (1);
	}
	return (0);
}
