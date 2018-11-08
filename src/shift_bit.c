/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:09:53 by amasol            #+#    #+#             */
/*   Updated: 2018/11/08 16:09:54 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

size_t		shift_bit(unsigned char tmp, unsigned char tmp2)
{
	int num1;
	int num2;
	size_t num3;

//	num1 = 0x25;
//	num2 = 0x71;
	num1 = (int)tmp;
	num2 = (int)tmp2;
	num3 = (num1 << 8) | (num2);
	return (num3);
}

