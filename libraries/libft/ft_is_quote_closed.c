/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_closed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:52:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:16:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if the quotes are closed.
 * @return TRUE if s_quotes and d_quotes are closed
 * 			FALSE if one of them is opened
 * first if / Considera apenas se não estamos dentro de aspas dupla
 * second if / Considera apenas se não estamos dentro de aspas simples
*/
int	ft_is_quote_closed(char *input)
{
	int	i;
	int	s_quotes;
	int	d_quotes;

	i = 0;
	s_quotes = 0;
	d_quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'' && d_quotes % 2 == 0)
			s_quotes++;
		else if (input[i] == '\"' && s_quotes % 2 == 0)
			d_quotes++;
		i++;
	}
	return (s_quotes % 2 == 0 && d_quotes % 2 == 0);
}
