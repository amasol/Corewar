/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:30:07 by amasol            #+#    #+#             */
/*   Updated: 2017/11/15 20:25:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ds;
	unsigned char	*st;
	int				i;

	i = 0;
	ds = (unsigned char *)s1;
	st = (unsigned char *)s2;
	if (ds == NULL && st == NULL)
		return (0);
	while ((ds[i] == st[i]) && ds[i] != '\0' && st[i] != '\0')
		i++;
	return (ds[i] - st[i]);
}
