/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures_ew.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:28:21 by pineau            #+#    #+#             */
/*   Updated: 2023/12/12 16:26:42 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*get_pixel_east(t_data *data, double ray)
{
	unsigned int	*image_data;
	unsigned int	*pixel;
	double			column;

	image_data = (unsigned int *)mlx_get_data_addr(data->ea->texture,
			&data->ea->bits_per_pixel,
			&data->ea->line_length,
			&data->ea->endian);
	column = (ray - ((double)(int)ray))
		/ (1.0f / data->ea->height);
	pixel = image_data;
	pixel += (unsigned int)column;
	return (pixel);
}

void	print_east(t_data *data, double len, double start, double ray)
{
	double			size;
	unsigned int	*pixel;
	unsigned int	color;
	int				i;

	size = len / data->ea->width;
	pixel = get_pixel_east(data, ray);
	i = 0;
	if (start + (size * i) < 0)
	{
		while (start + (size * i) < 0)
		{
			pixel += data->ea->height;
			i++;
		}
		pixel -= data->ea->height;
		i--;
	}
	while (i < data->ea->width && start + (size * i) < HEIGHT)
	{
		color = *pixel;
		print_line2(data, start + (size * i), start + (size * (i + 1)), color);
		pixel += data->ea->height;
		i++;
	}
}

unsigned int	*get_pixel_west(t_data *data, double ray)
{
	unsigned int	*image_data;
	unsigned int	*pixel;
	double			column;

	image_data = (unsigned int *)mlx_get_data_addr(data->we->texture,
			&data->we->bits_per_pixel,
			&data->we->line_length,
			&data->we->endian);
	column = (ray - ((double)(int)ray))
		/ (1.0f / data->we->height);
	pixel = image_data;
	pixel += data->we->width - 1 - (unsigned int)column;
	return (pixel);
}

void	print_west(t_data *data, double len, double start, double ray)
{
	double			size;
	unsigned int	*pixel;
	unsigned int	color;
	int				i;

	size = len / data->we->width;
	pixel = get_pixel_west(data, ray);
	i = 0;
	if (start + size * i < 0)
	{
		while (start + size * i < 0)
		{
			pixel += data->we->height;
			i++;
		}
		pixel -= data->we->height;
		i--;
	}
	while (i < data->we->width && start + size * i < HEIGHT)
	{
		color = *pixel;
		print_line2(data, start + size * i, start + size * (i + 1), color);
		pixel += data->we->height;
		i++;
	}
}
