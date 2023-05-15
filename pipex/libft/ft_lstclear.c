/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:12 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:32:13 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!temp || !del)
		return ;
	while (temp != NULL)
	{
		temp = temp->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
