/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:15:59 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:13:35 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new element. 
 * The variable ’content’ is initialized with the value of the 
 * parameter ’content’. 
 * The variable ’next’ is initialized to NULL.
 * @return The new element.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/* 
//function description
//The ft_lstnew function creates a new linked list node 
//with the provided content, allocating memory for it and 
//setting its 'next' pointer to NULL.
#include <stdio.h>

int	main(void)
{
	char *str;
	t_list *element;
	
	str = (char *)malloc(sizeof(char) * 7);
	str = "amauri";
	
	element = ft_lstnew((void *)str);
	printf("%s\n", (char *)element->content);
	
} */