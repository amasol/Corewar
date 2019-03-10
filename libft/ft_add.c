/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:48:31 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/11 16:48:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_str(char *buf, const char *need_add, int size1, int size2)
{
	char	*temp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	temp = (char*)malloc(size1 + size2 + 1);
	while (i < size1)
	{
		temp[i] = buf[i];
		i++;
	}
	while (k < size2)
	{
		temp[i] = need_add[k];
		i++;
		k++;
	}
	temp[i] = '\0';
	if (size1 != 0)
		free(buf);
	return (temp);
}
