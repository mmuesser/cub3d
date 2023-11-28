/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:30:53 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/28 14:17:01 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static char	*ft_rep(const char *str, char c, int i)
{
	int		lenght;
	int		j;
	char	*tmp;

	lenght = 0;
	while (str[i + lenght] != c && str[i + lenght])
		lenght++;
	tmp = (char *) malloc(sizeof(char) * (lenght + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (str[i] != c && str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static char	**ft_create_str(const char *str, char c, char **dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			dest[j] = ft_rep(str, c, i);
			if (!dest[j])
			{
				free_all(dest);
				return (NULL);
			}
		}
		j++;
		while (str[i] != c && str[i])
			i++;
	}
	return (dest);
}

static int	nb_chaines(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	char	**dest;

	if (!str)
		return (NULL);
	i = nb_chaines(str, c);
	dest = NULL;
	dest = (char **) malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	dest = ft_create_str(str, c, dest);
	if (!dest)
		return (NULL);
	dest[i] = NULL;
	return (dest);
}
