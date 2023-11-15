/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:08:33 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/15 18:10:46 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	free_all(char **file)
{
	int	i;
	
	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
}

int	len_tab(char *tmp)
{
	int	count;
	int	i;

	count = 1;
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '\n')
			count++;
	}
	return (count);
}

char	*fill_str(char *tmp, int len, int i)
{
	char	*str;
	int		j;

	// printf("len : %d\n", len);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j++ < len)
		str[j] = tmp[i++];
	str[j] = '\0';
	return (str);
}

char	**create_str(char **file, char *tmp)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	printf("%s\n", tmp);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i + j] && tmp[i + j] != '\n')
		{
			printf("tmp : [%d] ", tmp[j]);
			printf("j : %d - i : %d\n", j, i);
			j++;
		}
		printf("j : %d\n", j);
		file[k] = fill_str(tmp, j, i);
		if (!file[k])
		{
			free_all(file);
			return (NULL);
		}
		k++;
		i += j + 1;
	}
	file[k] = NULL;
	return (file);
}

char	**split_file(char *tmp)
{
	int		count;
	char	**file;

	// printf("%s\n", tmp);
	count = len_tab(tmp);
	file = (char **) malloc(sizeof(char *) * (count + 1));
	if (!file)
		return (NULL);
	file = create_str(file, tmp);
	if (!file)
		return (NULL);
	return (file);
}
