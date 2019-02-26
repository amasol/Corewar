/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:30:07 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:30:43 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check_accuracy(char *p, t_specifiers *s, int psz)
{
	char	*new;
	int		i;
	int		k;
	int		size;

	if (s->accuracy_value == 0 && p[0] == '0')
	{
		p[0] = '\0';
		return (p);
	}
	i = 0;
	k = 0;
	size = s->accuracy_value;
	new = (char*)malloc(size + 1);
	while (i < size)
		new[i++] = '0';
	new[i] = '\0';
	i = i - psz;
	while (k < psz)
		new[i++] = p[k++];
	free(p);
	return (new);
}

static char	*ft_check_sharp(char *p, t_specifiers *s, int *sharp)
{
	char	*new;
	int		add;
	int		i;

	if (s->type == 'U' || s->type == 'u')
		return (p);
	add = (s->type == 'o' || s->type == 'O') ? 1 : 2;
	add = (add == 1 && p[0] == '0') ? 0 : add;
	(*sharp) = add;
	new = (char*)malloc(add + ft_strlen(p) + 1);
	new[add + ft_strlen(p)] = '\0';
	if (add)
		new[0] = '0';
	if (add == 2)
		new[1] = (s->type == 'X') ? 'X' : 'x';
	i = 0;
	while (p[i])
	{
		new[add] = p[i];
		add++;
		i++;
	}
	free(p);
	return (new);
}

static char	*ft_check_width(char *p, t_specifiers *s, int psz, int sharp)
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
	i = (s->minus) ? 0 : i - psz;
	i = (c == '0') ? i + sharp : i;
	if (sharp > 0 && c == '0')
		new[0] = p[k++];
	if ((sharp - 1) > 0 && c == '0')
		new[1] = p[k++];
	while (k < psz)
		new[i++] = p[k++];
	free(p);
	return (new);
}

char		*ft_putoux(t_specifiers *s, uintmax_t digit, int *k)
{
	char	*part;
	int		v;
	int		sharp;

	part = ft_uitoa(digit, s);
	v = s->accuracy_value;
	sharp = 0;
	if (s->accuracy && ((int)ft_strlen(part) < v || (v == 0 && part[0] == '0')))
		part = ft_check_accuracy(part, s, (int)ft_strlen(part));
	if (s->sharp == 1 && (digit != 0 || (s->type != 'x' && s->type != 'X')))
		part = ft_check_sharp(part, s, &sharp);
	if (s->width > (int)ft_strlen(part))
		part = ft_check_width(part, s, (int)ft_strlen(part), sharp);
	(*k) += ft_strlen(part);
	return (part);
}
