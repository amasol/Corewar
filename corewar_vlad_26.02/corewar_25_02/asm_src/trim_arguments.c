/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:33:43 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/20 14:33:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*trim_arg(char *arg)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (arg[i] && (arg[i] == ' ' || arg[i] == '\t'))
		i++;
	j = ft_strlen(arg) - 1;
	while (arg[j] && (arg[j] == ' ' || arg[j] == '\t'))
		j--;
	if (j < i)
	{
		ft_strdel(&arg);
		return (NULL);
	}
	s = (char*)malloc(j - i + 1);
	k = 0;
	while (i <= j)
		s[k++] = arg[i++];
	s[k] = '\0';
	ft_strdel(&arg);
	return (s);
}

void		trim_arguments(char **array)
{
	int i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			array[i] = trim_arg(array[i]);
			i++;
		}
	}
}
