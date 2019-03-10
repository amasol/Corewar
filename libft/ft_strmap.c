/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:07:49 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/08 13:55:01 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char*)malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (*s)
		str[i++] = f(*s++);
	str[i] = '\0';
	return (str);
}
