/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:51:40 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/27 17:58:19 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	map_len(char *str)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (-1);
	fd = open(str, O_RDONLY);
	i = -1;
	j = 1;
	while (j != 0)
	{
		j = read(fd, tmp, 1);
		if (j == -1)
		{
			free(tmp);
			return (-1);
		}
		i++;
	}
	close (fd);
	free(tmp);
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
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = read(fd, tmp, len);
	tmp[len] = '\0';
	close(fd);
	if (count == -1)
		return free(tmp), (NULL);
	file = split_file_line(tmp);
	if (!file)
		return (NULL);
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

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

int	check_file(t_data *data, char *file_name)
{
	char	**file;

	if (check_ext(file_name, ".cub") == 1)
		return (1);
	file = get_file(file_name);
	if (!file)
		return (1);
	data = split_desc_and_map(data, file);
	if (check_desc(data->map->desc) == 1)
	{
		free_tab(file);
		return (1);
	}
	if (check_map(data->map->map) == 1)
	{
		// free_tab(file);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (1);
	}
	if (check_file(&data, av[1]) == 1)
	{
		printf("Error\npb fichier\n");
		return (1);
	}
	return (0);
}