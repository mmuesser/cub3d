/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:05:08 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/30 15:21:43 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	len_dest(char *tmp)
{
	int	count;
	int	i;

	count = 1;
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '\n' && tmp[i + 1] != '\0')
			count++;
	}
	return (count);
}

char	*fill_str(char *tmp, int len, int i)
{
	char	*str;
	int		j;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = -1;
	while (++j < len)
		str[j] = tmp[i++];
	str[j] = '\0';
	return (str);
}

char	**create_str(char **file, char *tmp)
{
	int	i;
	int	j;
	int	k;
	int	len;

	k = 0;
	i = 0;
	len = ft_strlen(tmp);
	while (i < len)
	{
		j = 0;
		while (tmp[i + j] && tmp[i + j] != '\n')
			j++;
		file[k] = fill_str(tmp, j, i);
		if (!file[k])
		{
			free_tab(file);
			return (NULL);
		}
		k++;
		i += j + 1;
	}
	return (file);
}

char	**split_file_line(char *tmp)
{
	int		count;
	char	**file;

	count = len_dest(tmp);
	file = (char **) malloc(sizeof(char *) * (count + 1));
	if (!file)
		return (NULL);
	file = create_str(file, tmp);
	if (!file)
		return (NULL);
	file[count] = NULL;
	return (file);
}