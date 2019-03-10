/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:39:05 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/20 16:39:07 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_type_reg(char *s)
{
	int	i;
	int	temp;

	if (s[0] == 'r')
	{
		i = 1;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (s[i] || i == 1)
			return (0);
		temp = atoi(s + 1);
		if (temp > 0 && temp <= REG_NUMBER && i <= 3)
			return (1);
	}
	return (0);
}

static int	is_type_dir(char *s)
{
	int i;

	if (s[0] == DIRECT_CHAR)
	{
		if (s[1] && s[1] == LABEL_CHAR)
		{
			i = 2;
			while (s[i])
				if (!ft_strchr(LABEL_CHARS, (int)s[i++]))
					return (0);
			if (i != 2)
				return (1);
		}
		else if (s[1])
		{
			i = (s[1] == '-') ? 2 : 1;
			if (!s[i])
				return (0);
			while (s[i] && ft_isdigit(s[i]))
				i++;
			if (s[i] == '\0')
				return (1);
		}
	}
	return (0);
}

static int	is_type_ind(char *s)
{
	int i;

	if (s[0] && s[0] == LABEL_CHAR)
	{
		i = 1;
		if (!s[i])
			return (0);
		while (s[i])
			if (!ft_strchr(LABEL_CHARS, (int)s[i++]))
				return (0);
		return (1);
	}
	else if (s[0])
	{
		i = (s[0] == '-') ? 1 : 0;
		if (!s[i])
			return (0);
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (s[i] == '\0')
			return (1);
	}
	return (0);
}

int			get_type(char *s)
{
	if (is_type_reg(s))
		return (T_REG);
	if (is_type_dir(s))
		return (T_DIR);
	if (is_type_ind(s))
		return (T_IND);
	return (0);
}
