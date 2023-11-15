/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:18:15 by mmuesser          #+#    #+#             */
/*   Updated: 2022/12/13 15:23:20 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (!ft_strchr(tmp, '\n') && file != 0)
	{
		file = read(fd, tmp, BUFFER_SIZE);
		if (file == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[file] = '\0';
		lens1 = ft_strlen(str);
		lens2 = ft_strlen(tmp);
		str = ft_strjoin(str, tmp, lens1, lens2);
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
	tmp = ft_strdup(*str, i);
	free(*str);
	*str = tmp;
	if (!*str)
		free(*str);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str[1024];
	int			i;

	str[fd] = ft_read(str[fd], fd);
	if (!str[fd])
		return (NULL);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	ft_fill(&str[fd], &dest);
	if (dest[0] == '\0')
	{
		free(str[fd]);
		free(dest);
		return (NULL);
	}
	return (dest);
}
