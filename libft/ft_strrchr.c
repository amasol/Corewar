/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:48:56 by amasol            #+#    #+#             */
/*   Updated: 2017/11/15 20:23:27 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *dst;

	dst = NULL;
	if (!ch)
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str > 0)
	{
		if (*str == ch)
			dst = (char *)str;
		str++;
	}
	return (dst);
}
