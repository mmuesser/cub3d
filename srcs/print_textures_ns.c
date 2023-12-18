/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures_ns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:28:14 by pineau            #+#    #+#             */
/*   Updated: 2023/12/12 16:26:48 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*get_pixel_north(t_data *data, double ray)
{
	unsigned int	*image_data;
	unsigned int	*pixel;
	double			column;

	image_data = (unsigned int *)mlx_get_data_addr(data->no->texture,
			&data->no->bits_per_pixel,
			&data->no->line_length,
			&data->no->endian);
	column = (ray - ((double)(int)ray))
		/ (1.0f / data->no->height);
	pixel = image_data;
	pixel += (unsigned int)column;
	return (pixel);
}

void	print_north(t_data *data, double len, double start, double ray)
{
	double			size;
	unsigned int	*pixel;
	unsigned int	color;
	int				i;

	size = len / data->no->width;
	pixel = get_pixel_north(data, ray);
	i = 0;
	if (start + size * i < 0)
	{
		while (start + size * i < 0)
		{
			pixel += data->no->height;
			i++;
		}
		pixel -= data->no->height;
		i--;
	}
	while (i < data->no->width && start + size * i < HEIGHT)
	{
		color = *pixel;
		print_line2(data, start + size * i, start + size * (i + 1), color);
		pixel += data->no->height;
		i++;
	}
}

unsigned int	*get_pixel_south(t_data *data, double ray)
{
	unsigned int	*image_data;
	unsigned int	*pixel;
	double			column;

	image_data = (unsigned int *)mlx_get_data_addr(data->so->texture,
			&data->so->bits_per_pixel,
			&data->so->line_length,
			&data->so->endian);
	column = (ray - ((double)(int)ray))
		/ (1.0f / data->so->height);
	pixel = image_data;
	pixel += data->so->width - 1 - (unsigned int)column;
	return (pixel);
}

void	print_south(t_data *data, double len, double start, double ray)
{
	double			size;
	unsigned int	*pixel;
	unsigned int	color;
	int				i;

	size = len / data->so->width;
	pixel = get_pixel_south(data, ray);
	i = 0;
	if (start + size * i < 0)
	{
		while (start + size * i < 0)
		{
			pixel += data->so->height;
			i++;
		}
		pixel -= data->so->height;
		i--;
	}
	while (i < data->so->width && start + size * i < HEIGHT)
	{
		color = *pixel;
		print_line2(data, start + size * i, start + size * (i + 1), color);
		pixel += data->so->height;
		i++;
	}
}
