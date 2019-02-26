/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:44:07 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:30:25 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	ft_check_base(t_specifiers *s)
{
	if (s->type == 'o' || s->type == 'O')
		return (8);
	if (s->type == 'U' || s->type == 'u')
		return (10);
	else
		return (16);
}

static char			*ft_checkx(char *part, t_specifiers *s)
{
	int i;
	int	add;

	i = 0;
	add = (s->type == 'X') ? 7 : 39;
	while (part[i] != '\0')
	{
		if (part[i] > 57)
			part[i] += add;
		i++;
	}
	return (part);
}

char				*ft_uitoa(uintmax_t digit, t_specifiers *s)
{
	char		*part;
	int			i;
	uintmax_t	base;
	uintmax_t	x;

	i = 0;
	base = ft_check_base(s);
	x = digit;
	while (x >= base && ++i)
		x = x / base;
	part = (char*)malloc(i + 2);
	part[i + 1] = '\0';
	x = digit;
	while (i >= 0)
	{
		part[i] = x % base + 48;
		x = x / base;
		i--;
	}
	if (s->type == 'x' || s->type == 'X' || s->type == 'p')
		part = ft_checkx(part, s);
	return (part);
}
