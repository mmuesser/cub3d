/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:18:12 by mmuesser          #+#    #+#             */
/*   Updated: 2023/05/03 18:35:06 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	if (c > 255)
		c -= 256;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return ((char *) &str[i]);
		i++;
	}
	if (c == str[i])
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, int lens1, int lens2)
{
	int		lenght;
	int		i;
	char	*dest;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	lenght = lens1 + lens2;
	dest = malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < lens1)
		dest[i] = s1[i];
	i = -1;
	while (++i < lens2)
		dest[i + lens1] = s2[i];
	dest[lenght] = '\0';
	free((char *) s1);
	return (dest);
}

char	*ft_strdup(const char *src, int start)
{
	char	*dest;
	int		lenght;
	int		i;

	lenght = ft_strlen2(src) - start;
	dest = malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
