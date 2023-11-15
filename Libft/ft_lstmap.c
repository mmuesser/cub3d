/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:37:56 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/15 18:00:22 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*tmp;

	if (!f || !del || !lst)
		return (NULL);
	dest = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			while (dest)
			{
				tmp = dest->next;
				del(dest->content);
				free(dest);
				dest = tmp;
			}
			free(dest);
			return (NULL);
		}
		ft_lstadd_back(&dest, tmp);
		lst = lst->next;
	}
	return (dest);
}
