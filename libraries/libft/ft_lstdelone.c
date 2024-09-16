/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:33:19 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief deletes a single node in a linked list,
 * freeing its content and memory, ensuring no memory leaks.
 * @param lst Node to be deleted
 * @param del function del.
 * @param void paramether to function del.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del (lst->content);
	free (lst);
}
