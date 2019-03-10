/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:16:53 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/16 18:16:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	reverse(unsigned int value, int size)
{
	unsigned int	reversed;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&value;
	n2 = (unsigned char *)&reversed;
	if (size == 1)
		return (value);
	if (size == 4)
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	else
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	return (reversed);
}
