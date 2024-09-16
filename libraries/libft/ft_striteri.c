/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:46:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:14:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function f to each character of 
 * the string passed as argument, 
 * and passing its index as first argument. 
 * Each character is passed by address to f 
 * to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i ++;
	}
}
/* 
//Function description
//ft_striteri applies a function f to each character of a string s 
//along with its index, incrementing the index and iterating through the string.
#include <stdio.h>

static void	test_function(unsigned int index, char *str)
{
	while (index < ft_strlen(str))
	{	
		if (index % 2 != 0 && (str[index] >= 97 && str[index] <= 122))
			str[index] -= 32;
		if (index % 2 == 0 && (str[index] >= 65 && str[index] <= 90))
			str[index] += 32;
		index ++;	
	}
}

int main(void)
{
	//TEST WORKING
	char str_test[] = "This is a test and will be ok";
	ft_striteri(str_test, test_function); 
	printf("%s", str_test);
}
 */