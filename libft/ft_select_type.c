/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:15:21 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:32:05 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_select_part1(t_specifiers *s, va_list ap, int *k)
{
	if (s->type == 'c' || s->type == 'C')
		return (ft_putc(s, va_arg(ap, int), k));
	if (s->type == '%')
		return (ft_putc(s, 37, k));
	if (s->type == 'S' || (s->type == 's' && s->l == 1))
		return (ft_put_bigs(s, va_arg(ap, int*), k));
	if (s->type == 's')
		return (ft_puts(s, va_arg(ap, char*), k));
	else
		return (NULL);
}

static char	*ft_select_part2(t_specifiers *s, va_list ap, int *k)
{
	if (s->type == 'D')
		return (ft_putd(s, va_arg(ap, long), k));
	if (s->z)
		return (ft_putd(s, va_arg(ap, size_t), k));
	if (s->j)
		return (ft_putd(s, va_arg(ap, intmax_t), k));
	if (s->ll)
		return (ft_putd(s, va_arg(ap, long long), k));
	if (s->l)
		return (ft_putd(s, va_arg(ap, long), k));
	if (s->h)
		return (ft_putd(s, (short)va_arg(ap, int), k));
	if (s->hh)
		return (ft_putd(s, (char)va_arg(ap, int), k));
	else
		return (ft_putd(s, va_arg(ap, int), k));
}

static char	*ft_select_part3(t_specifiers *s, va_list ap, int *k)
{
	if (s->type == 'p')
	{
		s->sharp = 1;
		return (ft_putoux(s, va_arg(ap, uintmax_t), k));
	}
	if (s->type == 'O')
		return (ft_putoux(s, va_arg(ap, unsigned long), k));
	if (s->type == 'U')
		return (ft_putoux(s, va_arg(ap, unsigned long), k));
	if (s->z)
		return (ft_putoux(s, va_arg(ap, size_t), k));
	if (s->j)
		return (ft_putoux(s, va_arg(ap, uintmax_t), k));
	if (s->ll)
		return (ft_putoux(s, va_arg(ap, unsigned long long), k));
	if (s->l)
		return (ft_putoux(s, va_arg(ap, unsigned long), k));
	if (s->h)
		return (ft_putoux(s, (unsigned short)va_arg(ap, unsigned int), k));
	if (s->hh)
		return (ft_putoux(s, (unsigned char)va_arg(ap, unsigned int), k));
	else
		return (ft_putoux(s, va_arg(ap, unsigned int), k));
}

char		*ft_select_type(t_specifiers *s, va_list ap, int *k)
{
	char tp;

	tp = s->type;
	if (tp == 'S' || tp == 'c' || tp == '%' || tp == 'C' || tp == 's')
		return (ft_select_part1(s, ap, k));
	if (tp == 'd' || tp == 'i' || tp == 'D')
		return (ft_select_part2(s, ap, k));
	if (tp == 'o' || tp == 'O' || tp == 'u' || tp == 'U')
		return (ft_select_part3(s, ap, k));
	if (tp == 'x' || tp == 'X' || tp == 'p')
		return (ft_select_part3(s, ap, k));
	if (s->type)
		return (ft_putc(s, (int)tp, k));
	else
		return (NULL);
}
