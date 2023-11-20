/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:09 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/20 19:07:19 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	*get_path(char *str)
{
	int		i;
	char	*path;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	path = &str[i];
	return (path);
}

int	check_desc(char **file)
{
	int		i;
	int		test;
	char	*path;

	i = -1;
	while (file[++i])
	{
		if (file[i][0] != '\0' 
			&& (ft_strncmp(file[i], "NO", 2) != 0
			&& ft_strncmp(file[i], "SO", 2) != 0
			&& ft_strncmp(file[i], "EA", 2) != 0
			&& ft_strncmp(file[i], "WE", 2) != 0
			&& ft_strncmp(file[i], "F", 1) != 0
			&& ft_strncmp(file[i], "C", 1) != 0))
		{
			printf("test 1\n");
			printf("Error\nBad file description\n");
			return (1);
		}
		if (file[i][0] !='\0' && (file[i][0] != 'F' && file[i][0] != 'C'))
		{
			path = get_path(file[i]);
			if (!path || check_ext(path, ".xpm") == 1)
			{
				printf("test 2\n");
				printf("Error\nBad file description\n");
				return (1);
			}
			test = open(path, O_RDONLY);
			if (test == -1)
			{
				printf("test 3\n");
				printf("Error\nBad file description\n");
				return (1);
			}
			close(test);
		}
	}
	return (0);
}
