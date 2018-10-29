/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:09:43 by amasol            #+#    #+#             */
/*   Updated: 2017/11/24 20:09:16 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (d[i] == s[i] && d[i] != '\0' && s[i] != '\0' && i < n - 1)
		i++;
	return (d[i] - s[i]);
}
