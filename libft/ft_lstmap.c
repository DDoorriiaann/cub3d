/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:05:02 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:05:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*lst2;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	lst2 = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, temp);
		lst = lst->next;
	}
	return (lst2);
}
