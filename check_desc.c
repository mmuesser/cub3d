/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:09 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:34 by mmuesser         ###   ########.fr       */
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

int	check_desc(char **desc)
{
	int		i;
	int		j;
	int		test;
	int		count;
	char	*path;

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
		{
			printf("Error\nBad file description\n");
			return (1);
		}
		if (desc[i][0] !='\0' && (desc[i][0] != 'F' && desc[i][0] != 'C'))
		{
			path = get_path(desc[i]);
			if (!path || check_ext(path, ".xpm") == 1)
			{
				printf("Error\nBad file description\n");
				return (1);
			}
			test = open(path, O_RDONLY);
			if (test == -1)
			{
				printf("Error\nBad file description\n");
				return (1);
			}
			close(test);
		}
		if (desc[i][0] !='\0' && (desc[i][0] == 'F' || desc[i][0] == 'C'))
		{
			count = 0;
			j = 0;
			while (desc[i][j])
			{
				while (desc[i][j] && (desc[i][j] != '0' && desc[i][j] != '1'
				&& desc[i][j] != '2' && desc[i][j] != '3'
				&& desc[i][j] != '4' && desc[i][j] != '5'
				&& desc[i][j] != '6' && desc[i][j] != '7'
				&& desc[i][j] != '8' && desc[i][j] != '9'
				&& desc[i][j] != '-'))
					j++;
				test = ft_atoi(&desc[i][j]);
				count++;
				if (test < 0 || test > 255 || count > 3)
				{
					printf("Error\nBad file description\n");
					return (1);
				}
				while (desc[i][j] && (desc[i][j] == '0' || desc[i][j] == '1'
				|| desc[i][j] == '2' || desc[i][j] == '3'
				|| desc[i][j] == '4' || desc[i][j] == '5'
				|| desc[i][j] == '6' || desc[i][j] == '7'
				|| desc[i][j] == '8' || desc[i][j] == '9')) //opti cette merde
					j++;
			}
		}
	}
	return (0);
}
