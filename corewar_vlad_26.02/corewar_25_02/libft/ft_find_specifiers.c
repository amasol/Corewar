/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:07:34 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:33:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_specifiers	*ft_default_specififiers(void)
{
	t_specifiers *s;

	s = (t_specifiers*)malloc(sizeof(t_specifiers));
	s->accuracy = 0;
	s->minus = 0;
	s->plus = 0;
	s->space = 0;
	s->sharp = 0;
	s->zero = 0;
	s->h = 0;
	s->hh = 0;
	s->l = 0;
	s->ll = 0;
	s->j = 0;
	s->z = 0;
	s->width = 0;
	s->accuracy_value = 0;
	s->type = 0;
	s->error_flag = 0;
	return (s);
}

static int			ft_find_flags(const char *f, int *i, t_specifiers *s)
{
	int	res;

	res = 0;
	while (f[*i] && (f[*i] == '-' || f[*i] == '+' || f[*i] == ' ' ||
		f[*i] == '#' || f[*i] == '0'))
	{
		res = 1;
		if (f[*i] == '-')
			s->minus = 1;
		if (f[*i] == '+')
			s->plus = 1;
		if (f[*i] == ' ')
			s->space = 1;
		if (f[*i] == '#')
			s->sharp = 1;
		if (f[*i] == '0')
			s->zero = 1;
		(*i)++;
	}
	return (res);
}

static int			ft_width_accuracy(const char *f, int *i, t_specifiers *s)
{
	int	res;

	res = 0;
	while (f[*i] && f[*i] >= 48 && f[*i] <= 57)
	{
		s->width = s->width * 10 + f[*i] - 48;
		(*i)++;
		res = 1;
	}
	if (f[*i] == '.')
	{
		s->accuracy = 1;
		(*i)++;
		res = 1;
		s->accuracy_value = 0;
		while (f[*i] && f[*i] >= 48 && f[*i] <= 57)
		{
			s->accuracy_value = s->accuracy_value * 10 + f[*i] - 48;
			(*i)++;
		}
	}
	return (res);
}

static int			ft_find_sz_modifier(const char *f, int *i, t_specifiers *s)
{
	if (f[*i] && (f[*i] == 'z' || f[*i] == 'j' || f[*i] == 'l' ||
		f[*i] == 'h'))
	{
		if (f[*i] == 'z')
			s->z = 1;
		else if (f[*i] == 'j')
			s->j = 1;
		else if (f[*i] == 'l' && f[*i + 1] && f[*i + 1] == 'l')
		{
			s->ll = 1;
			(*i)++;
		}
		else if (f[*i] == 'l')
			s->l = 1;
		else if (f[*i] == 'h' && f[*i + 1] && f[*i + 1] == 'h')
		{
			s->hh = 1;
			(*i)++;
		}
		else if (f[*i] == 'h')
			s->h = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

t_specifiers		*ft_find_specifiers(const char *f, int *i)
{
	t_specifiers	*s;
	int				counter;

	s = ft_default_specififiers();
	counter = 1;
	while (counter)
	{
		counter = 0;
		counter += ft_find_flags(f, i, s);
		counter += ft_width_accuracy(f, i, s);
		counter += ft_find_sz_modifier(f, i, s);
	}
	if (f[*i])
	{
		s->type = f[*i];
		(*i)++;
	}
	return (s);
}
