/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_opcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:23:40 by bdomansk          #+#    #+#             */
/*   Updated: 2018/12/01 17:23:42 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	find_opcode(char *s, int start)
{
	char	*name;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (g_operations[i].name)
	{
		name = g_operations[i].name;
		j = 0;
		k = start;
		while (s[k] && name[j] && s[k++] == name[j])
			j++;
		if (!name[j] && (!s[k] || s[k] == ' ' || s[k] == '\t' ||
			s[k] == '%' || s[k] == '-' || ft_isdigit(s[k])))
			return (g_operations[i].opcode);
		i++;
	}
	return (0);
}
