/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:09 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/29 17:27:16 by mmuesser         ###   ########.fr       */
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

int	check_line(char **desc)
{
	int	i;

	i = -1;
	while (desc[++i])
	{
		if (desc[i][0] != '\0'
			&& (ft_strncmp(desc[i], "NO", 2) != 0
			&& ft_strncmp(desc[i], "SO", 2) != 0
			&& ft_strncmp(desc[i], "EA", 2) != 0
			&& ft_strncmp(desc[i], "WE", 2) != 0
			&& ft_strncmp(desc[i], "F", 1) != 0
			&& ft_strncmp(desc[i], "C", 1) != 0))
			return (1);
	}
	return (0);
}

int	check_path(char **desc)
{
	int		i;
	int		test;
	char	*path;

	i = -1;
	while (desc[++i])
	{
		if (desc[i][0] != '\0' && (desc[i][0] != 'F' && desc[i][0] != 'C'))
		{
			path = get_path(desc[i]);
			if (!path || check_ext(path, ".xpm") == 1)
				return (1);
			test = open(path, O_RDONLY);
			if (test == -1)
				return (1);
			close(test);
		}
	}
	return (0);
}

int	check_rgb(char **desc, int test, int count)
{
	int	i;
	int	j;

	i = -1;
	while (desc[++i])
	{
		if (desc[i][0] != '\0' && (desc[i][0] == 'F' || desc[i][0] == 'C'))
		{
			count = 0;
			j = 0;
			while (desc[i][j])
			{
				while (desc[i][j] && ((desc[i][j] < '0' || desc[i][j] > '9')
					&& desc[i][j] != '-'))
					j++;
				test = ft_atoi(&desc[i][j]);
				count++;
				if (test < 0 || test > 255 || count > 3)
					return (1);
				while (desc[i][j] && (desc[i][j] >= '0' && desc[i][j] <= '9'))
					j++;
			}
		}
	}
	return (0);
}

int	check_desc(char **desc)
{
	if (check_line(desc) == 1)
		return (1);
	if (check_path(desc) == 1)
		return (1);
	if (check_rgb(desc, 0, 0) == 1)
		return (1);
	return (0);
}
