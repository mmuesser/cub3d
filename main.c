/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:51:40 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/14 18:11:55 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	**get_file(char *name_file)
{
	char	*tmp;
	char	**file;
	int		count;
	char	buffer;
	int		fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, &buffer, 1);
		if (count == -1)
		{
			//free
			return (NULL);
		}
		tmp = ft_strjoin(tmp, &buffer);
	}
	close(fd);
	file = ft_split(tmp, "\n");
	if (!file)
		return (NULL);
	free(tmp);
	return (file);
}

int	check_ext(char *name_file, char *ext)
{
	int	i;

	name_file = &name_file[ft_strlen(name_file) - 5];
	i = 0;
	while (name_file[i] || ext[i])
	{
		if (name_file[i] != ext[i])
			return (1);
		i++;
	}
	if (name_file[i] || ext[i])
		return (1);
	return (0);
}

int	check_desc_file(char **file)
{
	
}

int	check_file(char *name_file)
{
	char	**file;

	if (check_ext(name_file, ".cub") == 1)
		return (1);
	file = get_file(name_file);
	if (!file)
		return (1);
	if (check_desc_file(file) == 1)
	{
		//free(file);
		return (1);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (1);
	}
	if (check_file(av[1]) == 1)
	{
		printf("Error\npb map ou fichier\n");
		return (1);
	}
	return (0);
}