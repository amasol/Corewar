/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:56:21 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/11 19:02:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*substr;

	substr = (char*)needle;
	if (*substr == 0)
		return ((char*)haystack);
	while (*haystack != 0)
	{
		if (*haystack != *substr)
		{
			haystack++;
			continue;
		}
		str = (char*)haystack;
		while (*str++ == *substr++)
			if (*substr == 0)
				return ((char*)haystack);
		substr = (char*)needle;
		haystack++;
	}
	return (0);
}
