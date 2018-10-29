/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:28:40 by amasol            #+#    #+#             */
/*   Updated: 2017/11/13 20:01:04 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *rts)
{
	size_t	tak;
	size_t	i;
	size_t	j;

	i = 0;
	if (rts[i] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		tak = i;
		while (str[i] == rts[j])
		{
			i++;
			j++;
			if (!rts[j])
				return ((char *)&str[tak]);
		}
		i = tak;
		i++;
	}
	return (0);
}
