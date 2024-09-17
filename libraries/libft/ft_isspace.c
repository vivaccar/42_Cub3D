/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:50:06 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 19:16:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if the input is only spaces
 * @return true if only space, false for not
 */
int ft_isspace(char c)
{
    return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' ||
			c == '\f' || c == '\r');
}
