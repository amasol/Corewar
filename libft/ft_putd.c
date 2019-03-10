/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:48:56 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:35:30 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_check_sign(intmax_t digit, t_specifiers *s, int *i)
{
	if (digit < 0)
	{
		(*i)++;
		return ('-');
	}
	if (s->plus)
	{
		(*i)++;
		return ('+');
	}
	if (s->space)
	{
		(*i)++;
		return (' ');
	}
	else
		return (0);
}

static char		*ft_itoa_spec(intmax_t digit, t_specifiers *s)
{
	char		*part;
	char		sign;
	int			i;
	uintmax_t	x;

	i = 0;
	sign = ft_check_sign(digit, s, &i);
	x = (digit < 0) ? (-digit) : digit;
	while (x >= 10 && ++i)
		x = x / 10;
	part = (char*)malloc(sizeof(char) * (i + 2));
	part[i + 1] = '\0';
	x = (digit < 0) ? (-digit) : digit;
	while (i >= 1)
	{
		part[i] = x % 10 + 48;
		x = x / 10;
		i--;
	}
	part[0] = (sign != 0) ? sign : (x + 48);
	return (part);
}

static char		*ft_check_accuracy(char *p, t_specifiers *s, int psz, int sign)
{
	char	*new;
	int		i;
	int		k;
	int		size;

	if (s->accuracy_value == 0 && p[sign] == '0')
	{
		p[sign] = '\0';
		return (p);
	}
	i = 0;
	k = 0;
	size = (s->accuracy_value > psz) ? s->accuracy_value + sign : psz + sign;
	new = (char*)malloc(size + 1);
	while (i < size)
		new[i++] = '0';
	new[i] = '\0';
	if (sign)
		new[0] = p[k++];
	i = i - psz + sign;
	while (k < psz)
		new[i++] = p[k++];
	free(p);
	return (new);
}

static char		*ft_check_width(char *p, t_specifiers *s, int psz, int sign)
{
	char	*new;
	int		size;
	int		i;
	int		k;
	char	c;

	k = 0;
	i = 0;
	c = (s->accuracy == 0 && s->zero && s->minus == 0) ? '0' : ' ';
	size = s->width;
	new = (char*)malloc(size + 1);
	while (i < size)
		new[i++] = c;
	new[i] = '\0';
	i = (s->minus) ? 0 : i - psz + sign;
	if (sign && c == '0')
		new[0] = p[k++];
	else if (!s->minus && sign)
		i--;
	while (k < psz)
		new[i++] = p[k++];
	free(p);
	return (new);
}

char			*ft_putd(t_specifiers *s, intmax_t digit, int *k)
{
	char	*part;
	int		sign;

	part = ft_itoa_spec(digit, s);
	sign = (part[0] < 48 || part[0] > 57) ? 1 : 0;
	if (s->accuracy && ((int)ft_strlen(part) - sign < s->accuracy_value ||
	(s->accuracy_value == 0 && part[sign] == '0')))
		part = ft_check_accuracy(part, s, (int)ft_strlen(part), sign);
	if (s->width > (int)ft_strlen(part))
		part = ft_check_width(part, s, (int)ft_strlen(part), sign);
	(*k) += ft_strlen(part);
	return (part);
}
