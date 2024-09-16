/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matriz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:37:51 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clean ** of chars.
 * @attention Called at prompt.c;
*/
void	ft_free_matriz(char **dp_char)
{
	int	i;

	i = 0;
	if (!dp_char)
		return ;
	while (dp_char[i])
		free(dp_char[i ++]);
	free(dp_char);
}
