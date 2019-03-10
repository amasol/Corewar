/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:06:55 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/03 11:18:38 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	int				k;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	k = (int)n;
	str2 = (unsigned char*)dst;
	str1 = (unsigned char*)src;
	while (i < k)
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}
