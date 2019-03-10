/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:31:25 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/11 19:00:37 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	t1;
	unsigned char	t2;
	size_t			i;

	i = n;
	while (*s1 == *s2 && *s1 && i > 0)
	{
		s1++;
		s2++;
		i--;
	}
	if (i == 0)
		return (0);
	t1 = *s1;
	t2 = *s2;
	return (t1 - t2);
}
