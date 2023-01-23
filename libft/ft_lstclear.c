/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:53:13 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 11:53:39 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
}
