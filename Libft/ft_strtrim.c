/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:59:49 by mmuesser          #+#    #+#             */
/*   Updated: 2023/10/10 19:44:07 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	int		i;
	int		j;
	int		lenght;

	j = 0;
	while (in_set(s1[j], set))
		j++;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && in_set(s1[i], set))
		i--;
	lenght = i - j + 1;
	if (lenght < 0)
		return (strdup(""));
	dest = (char *) malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < lenght)
	{
		dest[i] = s1[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
