/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:54:46 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:16 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_src;
	unsigned char	*str_dest;

	i = 0;
	str_src = (unsigned char *)src;
	str_dest = dest;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return ((void *) str_dest);
}
