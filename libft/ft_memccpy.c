/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:59:47 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/03 11:18:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	ch;

	ch = (unsigned char)c;
	str2 = (unsigned char*)d;
	str1 = (unsigned char*)s;
	while (n)
	{
		if ((*str2++ = *str1++) == ch)
			return (str2);
		n--;
	}
	return (0);
}
