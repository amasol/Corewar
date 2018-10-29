/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:19:53 by amasol            #+#    #+#             */
/*   Updated: 2017/11/14 14:58:33 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	unsigned char	pam;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	pam = (unsigned char)c;
	while (i < n)
	{
		if ((ds[i] = sr[i]) == pam)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
