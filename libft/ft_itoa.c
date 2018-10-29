/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:21:32 by amasol            #+#    #+#             */
/*   Updated: 2017/11/24 20:03:34 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		cou(int n)
{
	int i;

	i = 0;
	i = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	filling(char *str, long int n, size_t l)
{
	if (n < 0)
	{
		str[0] = '-';
		str[l + 1] = '\0';
		str = str + l;
		n = -n;
	}
	else
	{
		str[l] = '\0';
		str = str + l - 1;
	}
	while (l--)
	{
		*str-- = ('0' + n % 10);
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = cou(n);
	if (n < 0 && (!(str = ft_memalloc(sizeof(char) * len + 2))))
		return (NULL);
	if (n >= 0 && (!(str = ft_memalloc(sizeof(char) * len + 1))))
		return (NULL);
	filling(str, n, len);
	return (str);
}
