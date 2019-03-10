/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:45:13 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:31:26 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillpart(t_specifiers *s, char *p2, char *p, int sz)
{
	int	i;
	int	k;

	i = 0;
	k = (s->minus > 0) ? 0 : ft_strlen(p2) - sz;
	while (i < sz)
	{
		p2[k] = p[i];
		k++;
		i++;
	}
	return (p2);
}

static char	*ft_puts_flags(t_specifiers *s, char *part, int *k)
{
	char	*part2;
	int		i;
	int		size;
	int		size2;
	char	iszero;

	i = 0;
	if (s->accuracy && s->accuracy_value < (int)ft_strlen(part))
		size = s->accuracy_value;
	else
		size = ft_strlen(part);
	size2 = (s->width > size) ? s->width : size;
	part2 = (char*)malloc(size2 + 1);
	iszero = (s->minus == 0 && s->zero == 1) ? '0' : ' ';
	while (i < size2)
	{
		part2[i] = iszero;
		i++;
	}
	part2[i] = '\0';
	(*k) += size2;
	return (ft_fillpart(s, part2, part, size));
}

char		*ft_puts(t_specifiers *s, char *part, int *k)
{
	char	*new;
	int		i;

	i = 0;
	if (!part)
		return (ft_puts(s, "(null)", k));
	if (s->minus || s->accuracy || s->width)
		return (ft_puts_flags(s, part, k));
	new = (char*)malloc(ft_strlen(part) + 1);
	while (part[i])
	{
		new[i] = part[i];
		i++;
	}
	new[i] = '\0';
	(*k) = (*k) + ft_strlen(new);
	return (new);
}
