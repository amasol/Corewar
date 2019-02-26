/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:11:10 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/13 18:46:26 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*substr;
	int		l;
	int		x;

	substr = (char*)needle;
	if (*substr == 0)
		return ((char*)haystack);
	l = (int)len;
	while (*haystack && l > 0)
	{
		x = l;
		if (*haystack == *substr)
		{
			str = (char*)haystack;
			while (*str++ == *substr++ && l-- > 0)
				if (*substr == 0)
					return ((char*)haystack);
			substr = (char*)needle;
		}
		l = x - 1;
		haystack++;
	}
	return (0);
}
