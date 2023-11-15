/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:58:36 by mmuesser          #+#    #+#             */
/*   Updated: 2023/09/29 00:43:56 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dest;
	int		lenght;

	lenght = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc(sizeof(char) * lenght + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
	{
		dest[i] = s2[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
