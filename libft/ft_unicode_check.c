/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:14:14 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/05 17:14:17 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Unicode mask
** 0xxxxxxx (7 bits - 0x7F)
** 110xxxxx (0XC0) 10xxxxxx (0x80)(11 bits - 0x7FF)
** 1110xxxx (0xE0) 10xxxxxx 10xxxxxx (16 bits - 0xFFFF)
** 11110xxx (0xF0) 10xxxxxx 10xxxxxx 10xxxxxx (21 bits - 0x1FFFFF)
** 00111111 (0x3F)
*/

char	*ft_unicode_check(int c, int *len)
{
	char	*buf;

	buf = (char*)malloc(5);
	if (c <= 0x7F && ((*len) = 1))
		buf[0] = c;
	else if (c <= 0x7FF && ((*len) = 2))
	{
		buf[0] = (c >> 6) + 0xC0;
		buf[1] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF && ((*len) = 3))
	{
		buf[0] = (c >> 12) + 0xE0;
		buf[1] = ((c >> 6) & 0x3F) + 0x80;
		buf[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x1FFFFF && ((*len) = 4))
	{
		buf[0] = (c >> 18) + 0xF0;
		buf[1] = ((c >> 12) & 0x3F) + 0x80;
		buf[2] = ((c >> 6) & 0x3F) + 0x80;
		buf[3] = (c & 0x3F) + 0x80;
	}
	buf[*len] = '\0';
	return (buf);
}
