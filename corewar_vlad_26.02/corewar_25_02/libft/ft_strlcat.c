/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:14:35 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/03 14:15:01 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dstlen;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = size;
	while (i-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	i = size - dstlen;
	if (i == 0)
		return (dstlen + ft_strlen(src));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
