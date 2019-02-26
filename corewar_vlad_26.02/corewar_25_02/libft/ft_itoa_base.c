/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:42:41 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/06 11:42:44 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Function work with base from 2 to 16
*/

static char	*ft_formatting(char *str, int base)
{
	int i;

	if (base > 10)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] > 57)
				str[i] = str[i] + 7;
			i++;
		}
	}
	return (str);
}

char		*ft_itoa_base(int number, int base)
{
	unsigned int	temp;
	int				i;
	int				sign;
	char			*str;

	if (base < 2 || base > 16)
		return (NULL);
	sign = (number < 0) ? 1 : 0;
	i = 0;
	temp = (number < 0) ? (-number) : number;
	while (temp >= (unsigned int)base && (++i))
		temp = temp / base;
	str = (char*)malloc(i + sign + 2);
	str[i + sign + 1] = '\0';
	str[0] = (sign) ? '-' : '0';
	temp = (number < 0) ? (-number) : number;
	i = i + sign;
	while (i >= sign)
	{
		str[i] = temp % base + 48;
		temp = temp / base;
		i--;
	}
	str = ft_formatting(str, base);
	return (str);
}
