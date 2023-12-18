/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:05:23 by pineau            #+#    #+#             */
/*   Updated: 2023/12/12 16:39:32 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char			*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = (img->addr + (y * img->line_length)
			+ (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

void	free_color(char **t)
{
	int	i;

	i = -1;
	while (t[++i])
		free(t[i]);
	free(t);
}

int	get_color(char *s)
{
	unsigned int	c;
	char			**tmp;

	tmp = ft_split(s, ',');
	c = 0;
	c = (ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
		+ (ft_atoi(tmp[2]) << 0);
	free_color(tmp);
	return (c);
}

void	find_rgb(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data->map->ceiling = 0;
	data->map->floor = 0;
	while ((!data->map->ceiling || !data->map->floor) && data->map->desc[i])
	{
		if (data->map->desc[i][0] == 'F')
		{
			while (data->map->desc[i][j] == ' ')
				j++;
			data->map->floor = get_color(data->map->desc[i] + j);
			j = 1;
		}
		if (data->map->desc[i][0] == 'C')
		{
			while (data->map->desc[i][j] == ' ')
				j++;
			data->map->ceiling = get_color(data->map->desc[i] + j);
			j = 1;
		}
		i++;
	}
}
