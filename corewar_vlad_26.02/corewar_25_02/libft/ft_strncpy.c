/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:39:31 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/03 11:44:05 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t size;

	if (ft_strlen(src) > len)
		size = len;
	else
		size = ft_strlen(src);
	if (size < len)
		ft_memset(dst + size, '\0', len - size);
	return (ft_memcpy(dst, src, size));
}
