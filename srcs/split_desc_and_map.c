/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_desc_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:14:02 by mmuesser          #+#    #+#             */
/*   Updated: 2023/12/18 18:05:53 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	len_desc(char **file)
{
	int	count_line;
	int	i;

	count_line = 0;
	i = -1;
	while (file[++i])
	{
		if (file[i] && file[i][0] != '\0')
			count_line++;
		if (count_line == 6)
			break ;
	}
	i++;
	return (i);
}

int	len_map(char **file, int l_desc)
{
	int	i;
	int	len;

	i = l_desc;
	while (file[i])
	{
		if (file[i] && file[i][0] != '\0')
			break ;
		i++;
	}
	len = 0;
	while (file[i])
	{
		len++;
		i++;
	}
	return (len);
}

t_data	*split_desc_and_map(t_data *data, char **file)
{
	int	i;
	int	j;
	int	l_desc;
	int	l_map;

	l_desc = len_desc(file);
	data->map->desc = (char **) malloc(sizeof(char *) * (l_desc + 1));
	if (!data->map->desc)
		return (NULL);
	i = -1;
	while (++i < l_desc)
		data->map->desc[i] = &file[i][0];
	data->map->desc[l_desc] = NULL;
	l_map = len_map(file, l_desc);
	data->map->map = (char **) malloc(sizeof(char *) * (l_map + 1));
	if (!data->map->map)
		return (free_tab(data->map->desc), NULL);
	while (file[i] && file[i][0] == '\0')
		i++;
	j = 0;
	while (file[i])
		data->map->map[j++] = &file[i++][0];
	data->map->map[l_map] = NULL;
	return (data);
}
