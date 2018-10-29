/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:10:04 by amasol            #+#    #+#             */
/*   Updated: 2017/11/24 20:16:28 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		st;
	int		i;
	int		k;

	if (s != '\0')
	{
		i = 0;
		st = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		while (s[st] == ' ' || s[st] == '\t' || s[st] == '\n')
			st--;
		str = (char *)malloc(sizeof(char) * (st - i) + 2);
		if (str == NULL)
			return (NULL);
		k = 0;
		while (i <= st)
			str[k++] = s[i++];
		str[k] = '\0';
		return (str);
	}
	return (0);
}
