/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:28:11 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/01 17:58:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	if (s2 <= s1 || s2 >= (s1 + len))
	{
		while (len--)
			*s2++ = *s1++;
	}
	else
	{
		s2 = s2 + len - 1;
		s1 = s1 + len - 1;
		while (len--)
			*s2-- = *s1--;
	}
	return (dst);
}
