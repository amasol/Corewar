/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:35:14 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/24 09:53:19 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;
	unsigned long int	x;

	x = 922337203685477580;
	sign = 1;
	res = 0;
	str = ft_whitespaces((char*)str);
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((res >= x || (res == x && *str - '0' > 7)) && sign == 1)
			return (-1);
		else if ((res > x || (res == x && *str - '0' > 8)) && sign == -1)
			return (0);
		str++;
	}
	return (res * sign);
}
