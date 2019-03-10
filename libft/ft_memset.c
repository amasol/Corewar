/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:02:19 by bdomansk          #+#    #+#             */
/*   Updated: 2017/10/31 18:02:02 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int val, size_t len)
{
	unsigned char	*str;
	long int		i;

	i = (long int)len;
	str = (unsigned char*)dst;
	while (--i >= 0)
		str[i] = (unsigned char)val;
	return (str);
}
