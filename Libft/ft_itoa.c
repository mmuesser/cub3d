/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:27 by mmuesser          #+#    #+#             */
/*   Updated: 2023/09/27 16:53:06 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght_str(int n)
{
	int				i;
	unsigned int	nb;

	i = 1;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	unsigned int	n;
	char			*dest;
	int				lenght;
	int				i;

	lenght = lenght_str(nb);
	dest = (char *) malloc(sizeof(char) * lenght + 1);
	if (!dest)
		return (NULL);
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	i = lenght - 1;
	while (i >= 0)
	{
		dest[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	if (nb < 0)
		dest[0] = '-';
	dest[lenght] = '\0';
	return (dest);
}
