/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:00:22 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:34:02 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_prepare(const char *f, int *i, int *k, va_list ap)
{
	t_specifiers	*specifiers;
	char			*part;

	(*i)++;
	specifiers = ft_find_specifiers(f, i);
	part = ft_select_type(specifiers, ap, k);
	free(specifiers);
	return (part);
}

static char	*ft_parse_format(const char *format, va_list ap, int *k)
{
	char	*buf;
	char	*need_to_add;
	int		i;
	int		temp;

	buf = NULL;
	i = 0;
	while (format[i])
	{
		temp = *k;
		if (format[i] == '%')
		{
			need_to_add = ft_prepare(format, &i, k, ap);
			buf = ft_add_str(buf, need_to_add, temp, (*k) - temp);
			if (need_to_add)
				free(need_to_add);
		}
		else
		{
			buf = ft_add_str(buf, &format[i++], temp, 1);
			(*k)++;
		}
	}
	return (buf);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	char	*buf;
	int		size;
	int		res;

	va_start(ap, format);
	size = 0;
	buf = ft_parse_format(format, ap, &size);
	va_end(ap);
	if (buf != NULL)
	{
		res = write(1, buf, size);
		free(buf);
		return (res);
	}
	return (0);
}
