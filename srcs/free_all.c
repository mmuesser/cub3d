/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:15:51 by mmuesser          #+#    #+#             */
/*   Updated: 2023/12/14 15:42:20 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->img)
		free(data->img);
}

void	free_data(t_data *data)
{
	if (data->file)
		free_tab(data->file);
	if (data->map->desc)
		free(data->map->desc);
	if (data->map->map)
		free(data->map->map);
	if (data->map)
		free(data->map);
}

void	free_rest(t_data *data)
{
	if (data->player)
		free(data->player);
}

int	free_all(t_data *data)
{
	if (data)
	{
		free_img(data);
		free_rest(data);
		free_data(data);
		free(data);
	}
	return (0);
}
