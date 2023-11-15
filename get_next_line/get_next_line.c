/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:36 by mmuesser          #+#    #+#             */
/*   Updated: 2023/05/03 18:36:10 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*tmp;
	int		file;
	int		lens1;
	int		lens2;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	file = 1;
	while (!ft_strchr2(tmp, '\n') && file != 0)
	{
		file = read(fd, tmp, BUFFER_SIZE);
		if (file == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[file] = '\0';
		lens1 = ft_strlen2(str);
		lens2 = ft_strlen2(tmp);
		str = ft_strjoin2(str, tmp, lens1, lens2);
	}
	free(tmp);
	return (str);
}

void	ft_fill(char **str, char **dest)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = *str;
	tmp2 = *dest;
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
	{
		tmp2[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		tmp2[i] = tmp[i];
		i++;
	}
	tmp2[i] = '\0';
	tmp = ft_strdup2(*str, i);
	free(*str);
	*str = tmp;
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str;
	int			i;

	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	ft_fill(&str, &dest);
	if (dest[0] == '\0')
	{
		free(str);
		free(dest);
		return (NULL);
	}
	return (dest);
}
