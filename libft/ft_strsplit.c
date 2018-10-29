/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:06:32 by amasol            #+#    #+#             */
/*   Updated: 2017/11/24 20:15:43 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_characters(char const *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	size_t	j;
	size_t	k;

	if (!s || !(str = (char **)malloc(sizeof(*str) *
		(ft_score(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_score(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew(f_characters(&s[j], c) + 1)))
			str[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
