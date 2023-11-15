/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:57:46 by mmuesser          #+#    #+#             */
/*   Updated: 2023/08/28 15:37:08 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	lenght;
	size_t	i;

	if (start > (size_t) ft_strlen(s))
	{
		dest = ft_strdup("");
		return (dest);
	}
	i = start;
	lenght = 0;
	while (s[i + lenght] && lenght < len)
		lenght++;
	dest = (char *) malloc(sizeof(char) * lenght + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len && s[start])
	{
		dest[i] = s[start];
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
