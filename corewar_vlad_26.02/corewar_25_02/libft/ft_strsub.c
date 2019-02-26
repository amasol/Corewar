/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:59:32 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/08 15:25:17 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!s)
		return (0);
	str = (char*)malloc(len + 1);
	if (!str)
		return (0);
	while (j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
