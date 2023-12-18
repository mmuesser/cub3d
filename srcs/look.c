/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:06:59 by pineau            #+#    #+#             */
/*   Updated: 2023/12/06 16:02:52 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	look(t_data *data, int mode)
{
	int	line_x;
	int	line_y;

	line_x = 0;
	line_y = 0;
	if (data->player->a >= 3 * M_PI / 2 || data->player->a <= M_PI / 2)
		line_x = look_right(data);
	else
		line_x = look_left(data);
	if (data->player->a <= M_PI || data->player->a > 2 * M_PI)
		line_y = look_bot(data);
	else
		line_y = look_top(data);
	if (mode == 1)
		return (line_x);
	if (mode == 2)
		return (line_y);
	else
		return (0);
}

int	look_right(t_data *data)
{
	int	line;

	line = (int)data->player->xx;
	line = line + 1;
	return (line);
}

int	look_left(t_data *data)
{
	int	line;

	line = (int)data->player->xx;
	return (line);
}

int	look_top(t_data *data)
{
	int	line;

	line = (int)data->player->yy;
	return (line);
}

int	look_bot(t_data *data)
{
	int	line;

	line = (int)data->player->yy;
	line = line + 1;
	return (line);
}
