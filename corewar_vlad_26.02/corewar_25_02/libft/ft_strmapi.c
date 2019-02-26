/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:09:32 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/08 14:20:32 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char*)malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (*s)
	{
		str[i] = f(i, *s++);
		i++;
	}
	str[i] = '\0';
	return (str);
}
