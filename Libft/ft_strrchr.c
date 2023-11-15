/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:40:37 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/20 15:34:06 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_str;

	if (c > 255)
		c -= 256;
	len_str = ft_strlen(s);
	while (len_str >= 0)
	{
		if (c == s[len_str])
			return ((char *)&s[len_str]);
		len_str--;
	}
	return (NULL);
}
