/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:34:32 by pineau            #+#    #+#             */
/*   Updated: 2023/12/12 16:08:48 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hook(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, ClientMessage, LeaveWindowMask, cross_p, data);
	mlx_loop(data->mlx);
}

int	cross_p(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == KEY_ESCAPE)
		mlx_loop_end(data->mlx);
	if (keysym == KEY_LEFT)
		key_left(data);
	if (keysym == KEY_RIGHT)
		key_right(data);
	if (keysym == KEY_S)
		key_down(data);
	if (keysym == KEY_W)
		key_up(data);
	if (keysym == KEY_A)
		key_a(data);
	if (keysym == KEY_D)
		key_d(data);
	return (0);
}
