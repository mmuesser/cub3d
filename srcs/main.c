/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:41:20 by pineau            #+#    #+#             */
/*   Updated: 2024/01/08 17:17:23 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*new_image(t_data *data)
{
	data->img->img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img_ptr)
	{
		free(data->img);
		return (NULL);
	}
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	return (data->img);
}

void	replace_map(char **strarray, int rows)
{
	int		i;
	char	*currentstring;

	i = 0;
	while (i < rows)
	{
		currentstring = strarray[i];
		while (*currentstring)
		{
			if (*currentstring == ' ')
				*currentstring = '1';
			++currentstring;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (init_data(data) == 0)
		return (free_all(data));
	if (init_images(data) == 0)
		return (free_all(data));
	data->file = NULL;
	data = parsing(data, argc, argv);
	if (!data)
		return (0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img = new_image(data);
	init_player(data);
	fill_path(data);
	while (data->map->map[i])
		replace_map(data->map->map, i++);
	draw_all(data);
	init_hook(data);
	return (end(data), 0);
}

void	end(t_data *data)
{
	if (data->img->img_ptr)
		mlx_destroy_image(data->mlx, data->img->img_ptr);
	if (data->no->texture)
		mlx_destroy_image(data->mlx, data->no->texture);
	if (data->so->texture)
		mlx_destroy_image(data->mlx, data->so->texture);
	if (data->we->texture)
		mlx_destroy_image(data->mlx, data->we->texture);
	if (data->ea->texture)
		mlx_destroy_image(data->mlx, data->ea->texture);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->no->path);
	free(data->so->path);
	free(data->we->path);
	free(data->ea->path);
	free_all(data);
}
