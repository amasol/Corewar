/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:38:59 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/03 14:14:18 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	size;
	char	*s;

	s = dst;
	dst = dst + ft_strlen(dst);
	if (ft_strlen(src) < n)
		size = ft_strlen(src);
	else
		size = n;
	dst[size] = '\0';
	ft_memcpy(dst, src, size);
	return (s);
}
