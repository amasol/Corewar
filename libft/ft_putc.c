/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:57:31 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:31:44 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_putc_width(t_specifiers *s, char *part, int *k, int len)
{
	char	*new;
	char	iszero;
	int		i;
	int		j;

	i = 0;
	new = (char*)malloc(s->width + 1);
	iszero = (s->zero == 1 && s->minus == 0) ? '0' : ' ';
	while (i < s->width)
		new[i++] = iszero;
	i = (s->minus == 1) ? 0 : s->width - len;
	j = 0;
	while (j < len)
		new[i++] = part[j++];
	new[s->width] = '\0';
	(*k) = (*k) + s->width;
	free(part);
	return (new);
}

char			*ft_putc(t_specifiers *s, int ch, int *k)
{
	char	*part;
	char	c;
	int		len;

	if (s->type == 'c' && s->l != 1)
	{
		len = 1;
		part = (char*)malloc(2);
		part[0] = (char)ch;
		part[1] = '\0';
	}
	else
		part = ft_unicode_check(ch, &len);
	c = (char)ch;
	if (s->width > len)
		return (ft_putc_width(s, part, k, len));
	(*k) += len;
	return (part);
}
