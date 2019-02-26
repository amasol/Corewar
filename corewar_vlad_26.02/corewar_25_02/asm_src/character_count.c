/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:40:10 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/17 16:40:12 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		character_count(char c, char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				count++;
			i++;
		}
	}
	return (count);
}
