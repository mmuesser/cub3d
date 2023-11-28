/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:15:51 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:02 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	free_data(t_data *data)
{
	if (data->img)
		free(data->img);
	if (data->map->desc)
		free(data->map->desc);
	if (data->map->map)
		free(data->map->map);
	if (data->map)
		free(data->map);
}

int	free_all(t_data *data)
{
	free_data(data);
	return (0);
}
