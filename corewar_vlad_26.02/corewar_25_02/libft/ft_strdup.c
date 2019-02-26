/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:49:48 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/02 16:41:24 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*copy;
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + 1;
	copy = (void*)malloc(len);
	if (copy == 0)
		return (0);
	res = (char*)ft_memcpy(copy, s1, len);
	return (res);
}
