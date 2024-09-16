/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:20:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:37:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node in a linked list by  
 * iteratively traversing it and returning the final node.
 * @param lst Node.
 * @return Last node on a linked list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/* 
//function description
//The ft_lstlast function returns the last node in a linked 
//list by iteratively traversing it and returning the final node.

#include <stdio.h>

int	main(void)
{
	t_list *list;
	//create newlist
	list = ft_lstnew("list 1");
	list->next = ft_lstnew("list 2");
	list->next->next = ft_lstnew("list 3");

	//define *last as the last node of the list
	t_list *last = ft_lstlast(list);
	//print the last
	printf("The last node is => %s", (char *)last->content);
} */