/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:13:18 by amasol            #+#    #+#             */
/*   Updated: 2017/11/12 18:25:33 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*std;
	int				res;

	res = 0;
	dst = (unsigned char *)s1;
	std = (unsigned char *)s2;
	while (0 < n)
	{
		if ((res = *dst - *std) != 0)
			break ;
		dst++;
		std++;
		n--;
	}
	return (res);
}
