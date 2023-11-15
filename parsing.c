/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:51:40 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/15 18:09:32 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	**get_file(char *file_name)
{
	char	*tmp;
	char	**file;
	int		count;
	char	buffer;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = malloc(sizeof(char) * 1);
	tmp[0] = '\0';
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
	file = split_file(tmp);
	if (!file)
		return (NULL);
	free(tmp);
	return (file);
}

int	check_ext(char *file_name, char *ext)
{
	int	i;

	file_name = &file_name[ft_strlen(file_name) - 4];
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

// int	check_desc_file(char **file)
// {
	
// }

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("[%s]\n", tab[i]);
}

int	check_file(char *file_name)
{
	char	**file;

	if (check_ext(file_name, ".cub") == 1)
		return (1);
	file = get_file(file_name);
	if (!file)
		return (1);
	print_tab(file);
	// if (check_desc_file(file) == 1)
	// {
	// 	//free(file);
	// 	return (1);
	// }
	return (0);
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