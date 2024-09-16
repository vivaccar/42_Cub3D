/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:36:12 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:31:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears a linked list by iteratively deleting each node and
 * its associated content using a provided deletion function (del).
 * @param lst Pointer to the linked list.
 * @param del function del.
 * @param void paramether to function del.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = *lst;
	if (!lst)
		return ;
	while (current_node)
	{
		next_node = current_node->next;
		del (current_node->content);
		free (current_node);
		current_node = next_node;
	}
	*lst = NULL;
}
