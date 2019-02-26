/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:55:04 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/10 10:42:31 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static int	ft_chars(char const *s, char c, int j)
{
	int i;

	i = j;
	while (s[i] && s[i] != c)
		i++;
	return (i - j);
}

static char	*ft_create_arr_i(const char *s, char c, char *str, int j)
{
	int i;

	i = 0;
	while (s[j] && s[j] != c)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

static char	**ft_create_arr(char const *s, char c, char **arrstr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			if (!(arrstr[i] = (char*)malloc(ft_chars(s, c, j) + 1)))
				return (0);
			arrstr[i] = ft_create_arr_i(s, c, arrstr[i], j);
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
	}
	arrstr[i] = 0;
	return (arrstr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arrstr;
	int		i;

	i = 0;
	if (!s || !c)
		return (0);
	if (!(arrstr = (char**)malloc(sizeof(char*) * ft_words(s, c) + 1)))
		return (0);
	arrstr = ft_create_arr(s, c, arrstr);
	i = 0;
	while (i < ft_words(s, c))
	{
		if (!arrstr[i])
			free(arrstr[i]);
		i++;
	}
	return (arrstr);
}
