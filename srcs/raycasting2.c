/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:08:02 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 14:08:08 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_ray2(t_data *data)
{
	double	i;
	double	k;

	i = draw_rayx2(data);
	k = draw_rayy2(data);
	if (i < 0)
		i = i * (-1);
	if (k < 0)
		k = k * (-1);
	if (k < i)
	{
		data->player->line += k;
		if (hit_wall2(data, k, 1) == 1)
			return (data->player->line = 0, 1);
	}
	else
	{
		data->player->line += i;
		if (hit_wall2(data, i, 2) == 1)
			return (data->player->line = 0, 1);
	}
	data->player->line = 0;
	return (0);
}
