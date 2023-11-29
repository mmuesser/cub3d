/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:11:37 by mmuesser          #+#    #+#             */
/*   Updated: 2023/11/29 17:34:37 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	error(int i)
{
	if (i == 1)
		printf("Error\nBad file extension\n");
	if (i == 2)
		printf("Error\nMalloc error\n");
	if (i == 3)
		printf("Error\nBad file description\n");
	if (i == 4)
		printf("Error\nBad map description\n");
	if (i == 5)
		printf("Error\nThe file does not exist\n");
	if (i == 6)
		printf("Error\nWrong number of arguments\n");
	return (1);
}
