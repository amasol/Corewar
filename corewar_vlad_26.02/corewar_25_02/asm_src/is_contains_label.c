/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_contains_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:09:58 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/27 18:10:02 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_contains_label(char *s, int i)
{
	int start;

	start = i;
	while (s[i] && s[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, s[i]))
			return (0);
		i++;
	}
	if (i != start && s[i] == LABEL_CHAR)
		return (1);
	return (0);
}
