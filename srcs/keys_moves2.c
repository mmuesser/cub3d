/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:12:17 by pineau            #+#    #+#             */
/*   Updated: 2023/12/14 14:12:19 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_data *data)
{
	data->player->a -= 0.05;
	if (data->player->a < 0)
		data->player->a += 2 * M_PI;
	data->player->dx = cos(data->player->a) * 10;
	data->player->dy = sin(data->player->a) * 10;
	draw_all(data);
}
