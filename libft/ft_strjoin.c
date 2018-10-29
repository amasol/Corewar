/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:12:14 by amasol            #+#    #+#             */
/*   Updated: 2018/03/15 16:36:14 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*fnew;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fnew = (char *)malloc(sizeof(*fnew) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fnew)
		return (NULL);
	while (*s1)
	{
		fnew[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		fnew[i] = *s2;
		s2++;
		i++;
	}
	fnew[i] = '\0';
	return (fnew);
}
