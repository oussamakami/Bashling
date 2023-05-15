/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:23 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:46:02 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstclearr(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!temp || !del)
		return (NULL);
	while (temp != NULL)
	{
		temp = temp->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*head;
	t_list	*temp;
	t_list	*p;
	int		n;

	i = 0;
	head = NULL;
	n = ft_lstsize(lst);
	while (i++ < n)
	{
		temp = ft_lstnew(f(lst->content));
		lst = lst->next;
		if (!temp)
			ft_lstclearr(&head, del);
		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			ft_lstadd_back(&p, temp);
		}
	}
	return (head);
}
