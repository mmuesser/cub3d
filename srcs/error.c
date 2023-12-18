/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:11:37 by mmuesser          #+#    #+#             */
/*   Updated: 2023/12/18 17:49:13 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(int i)
{
	if (i == 1)
		printf("Error\nBad file extension\n");
	else if (i == 2)
		printf("Error\nMalloc error\n");
	else if (i == 3)
		printf("Error\nBad file description\n");
	else if (i == 4)
		printf("Error\nBad map description\n");
	else if (i == 5)
		printf("Error\nThe file does not exist\n");
	else if (i == 6)
		printf("Error\nWrong number of arguments\n");
	return (1);
}
