/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:35:41 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/04 18:07:59 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		count;

	ch = (char)c;
	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	while (*s != ch)
	{
		if (count == 0)
			return (0);
		s--;
		count--;
	}
	return ((char*)s);
}
