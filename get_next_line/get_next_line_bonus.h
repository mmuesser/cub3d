/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:18:08 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/30 11:00:04 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_read(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2, int lens1, int lens2);
char	*ft_strdup(const char *src, int start);
int		ft_strlen(const char *str);
void	ft_fill(char **str, char **s1);

#endif