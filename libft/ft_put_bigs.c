/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bigs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:06:36 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:30:08 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_puts_flags(t_specifiers *s, char *part, int *k, int len)
{
	char	*new;
	int		i;
	int		j;
	int		size;
	char	iszero;

	i = 0;
	size = (s->width > len) ? s->width : len;
	new = (char*)malloc(size + 1);
	iszero = (s->minus == 0 && s->zero == 1) ? '0' : ' ';
	while (i < size)
	{
		new[i] = iszero;
		i++;
	}
	new[i] = '\0';
	(*k) += size;
	i = 0;
	j = (s->minus > 0) ? 0 : size - len;
	while (i < len)
		new[j++] = part[i++];
	return (new);
}

static char	*ft_parse_array(t_specifiers *s, int *str, int *size)
{
	char	*need_to_add;
	char	*part;
	int		len_need_to_add;
	int		i;

	i = 0;
	while (str[i])
	{
		len_need_to_add = 0;
		need_to_add = ft_unicode_check(str[i], &len_need_to_add);
		if (s->accuracy && s->accuracy_value < (*size) + len_need_to_add)
		{
			if (len_need_to_add)
				free(need_to_add);
			break ;
		}
		part = ft_add_str(part, need_to_add, (*size), len_need_to_add);
		(*size) += len_need_to_add;
		if (len_need_to_add)
			free(need_to_add);
		i++;
	}
	return (part);
}

char		*ft_put_bigs(t_specifiers *s, int *str, int *k)
{
	char	*part;
	int		size;

	if (!str && (s->type = 's'))
		return (ft_puts(s, "(null)", k));
	if (!str[0])
		return (NULL);
	size = 0;
	part = ft_parse_array(s, str, &size);
	if (s->minus || s->width)
		return (ft_puts_flags(s, part, k, size));
	(*k) = (*k) + size;
	return (part);
}
