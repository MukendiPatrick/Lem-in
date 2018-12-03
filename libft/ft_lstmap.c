/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:44:55 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/03 19:00:19 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nl;
	t_list	*head;

	if (!lst)
		return (NULL);
	nl = NULL;
	nl = (t_list *)malloc(sizeof(t_list));
	if (!(nl))
		return (NULL);
	nl = f(lst);
	head = nl;
	lst = lst->next;
	while (lst)
	{
		nl->next = f(lst);
		nl = nl->next;
		lst = lst->next;
	}
	return (head);
}
