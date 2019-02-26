/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:25:18 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/01 17:52:28 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;
	unsigned char	ch;

	if (n == 0)
		return (0);
	ch = (unsigned char)c;
	st = (unsigned char*)s;
	while (n--)
		if (*st++ == ch)
			return ((void*)(st - 1));
	return (0);
}
