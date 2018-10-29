/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:49:19 by amasol            #+#    #+#             */
/*   Updated: 2017/11/26 19:24:25 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t dst_end;
	size_t j;

	i = 0;
	j = ft_strlen(src);
	if (!len)
		return (j);
	while (dst[i] && (i < len))
		i++;
	dst_end = i;
	while (src[i - dst_end] && i < len - 1)
	{
		dst[i] = src[i - dst_end];
		i++;
	}
	if (dst_end < len)
		dst[i] = '\0';
	return (dst_end + j);
}
