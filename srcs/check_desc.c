/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:09 by mmuesser          #+#    #+#             */
/*   Updated: 2024/01/08 17:49:17 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_number(char **desc)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split("NO SO EA WE F C", ' ');
	if (!tmp)
		return (1);
	j = 0;
	i = -1;
	while (desc[++i])
	{
		if (j == 6)
			break ;
		if (ft_strncmp(desc[i], tmp[j], ft_strlen(tmp[j])) == 0)
		{
			j++;
			i = -1;
			continue ;
		}
	}
	if (j != 6)
		return (free_tab(tmp), 1);
	else
		return (free_tab(tmp), 0);
}

int	check_line(char **desc)
{
	int	i;

	i = -1;
	while (desc[++i])
	{
		if (desc[i][0] != '\0'
			&& (ft_strncmp(desc[i], "NO ", 3) != 0
			&& ft_strncmp(desc[i], "SO ", 3) != 0
			&& ft_strncmp(desc[i], "EA ", 3) != 0
			&& ft_strncmp(desc[i], "WE ", 3) != 0
			&& ft_strncmp(desc[i], "F ", 2) != 0
			&& ft_strncmp(desc[i], "C ", 2) != 0))
			return (1);
		if (check_number(desc) == 1)
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

int	check_rgb(char **desc, int test, int count, int i)
{
	int	j;

	i = -1;
	while (desc[++i])
	{
		if (desc[i][0] != '\0' && (desc[i][0] == 'F' || desc[i][0] == 'C'))
		{
			count = 0;
			j = 1;
			while (desc[i][j])
			{
				while (desc[i][j] && ((count == 0 && (desc[i][j] == ' '
					|| desc[i][j] == '	')) || (count > 0 && (desc[i][j] == ','
					&& (desc[i][j + 1] >= '0' && desc[i][j + 1] <= '9')))))
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
	if (check_rgb(desc, 0, 0, 0) == 1)
		return (1);
	return (0);
}
