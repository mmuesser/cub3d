/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:38:36 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/29 17:45:14 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	fill_line(char **line, char *src, int len)
{
	int	i;

	i = -1;
	while (src[++i])
		(*line)[i] = src[i];
	while (i < len)
	{
		(*line)[i] = ' ';
		i++;
	}
	(*line)[i] = '\0';
}

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

int	max_len(char **map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			;
		if (j > max)
			max = j;
	}
	return (max);
}

int	len_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}