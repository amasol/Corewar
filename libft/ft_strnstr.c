/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:05:17 by amasol            #+#    #+#             */
/*   Updated: 2017/11/13 19:47:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		while (s1[i + k] && (i + k) < len && s1[i + k] == s2[k])
			k++;
		if (s2[k] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
