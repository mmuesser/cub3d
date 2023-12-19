/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:51:40 by mmuesser          #+#    #+#             */
/*   Updated: 2023/12/19 07:54:22 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_len(char *str)
{
	int		i;
	int		j;
	int		fd;
	char	tmp;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = -1;
	j = 1;
	while (j != 0)
	{
		j = read(fd, &tmp, 1);
		if (j == -1)
			return (-1);
		i++;
	}
	close (fd);
	return (i);
}

char	**get_file(char *file_name)
{
	char	*tmp;
	char	**file;
	int		count;
	int		len;
	int		fd;

	len = map_len(file_name);
	if (len == -1)
		return (error(5), NULL);
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (free(tmp), error(5), NULL);
	count = read(fd, tmp, len);
	tmp[len] = '\0';
	close(fd);
	if (count == -1)
		return (free(tmp), NULL);
	file = split_file_line(tmp);
	if (!file)
		return (free(tmp), NULL);
	free(tmp);
	return (file);
}

int	check_ext(char *file_name, char *ext)
{
	int	i;

	file_name = &file_name[ft_strlen(file_name) - ft_strlen(ext)];
	i = 0;
	while (file_name[i] || ext[i])
	{
		if (file_name[i] != ext[i])
			return (1);
		i++;
	}
	if (file_name[i] || ext[i])
		return (1);
	return (0);
}

t_data	*check_file(t_data *data, char *file_name)
{
	if (check_ext(file_name, ".cub") == 1)
		return (free_all(data), error(1), NULL);
	data->file = get_file(file_name);
	if (!data->file)
		return (free_all(data), NULL);
	data = split_desc_and_map(data, data->file);
	if (!data)
		return (error(2), NULL);
	if (check_desc(data->map->desc) == 1)
		return (free_all(data), error(3), NULL);
	if (check_map(data->map->map) == 1)
		return (free_all(data), error(4), NULL);
	return (data);
}

t_data	*parsing(t_data *data, int ac, char **av)
{
	if (ac != 2)
		return (free_all(data), error(6), NULL);
	data = check_file(data, av[1]);
	if (!data)
		return (NULL);
	return (data);
}
