/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:33:10 by amasol            #+#    #+#             */
/*   Updated: 2017/11/13 22:01:33 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi(const char *str)
{
	char				*s;
	int					nom;
	int					negativ;

	s = (char *)str;
	nom = 0;
	negativ = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		negativ = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		nom = nom * 10 + *s - 48;
		s++;
	}
	nom *= negativ;
	return (nom);
}
