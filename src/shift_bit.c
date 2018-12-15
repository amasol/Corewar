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

//	printf("tmp = %x\n", tmp);
//	num1 = 0x25;
//	num2 = 0x71;
	num1 = (int)tmp;
	num2 = (int)tmp2;
	num3 = (num1 << 8) | (num2);
//	printf("num = %zu, %lu\n", num3, sizeof(size_t));
	return (num3);
}


//unsigned	shift_bit(unsigned char *buff)
//{
//	unsigned int 	buf[4];
//	unsigned int 	i;
//	size_t 	i;
////
//	i = 0;
//	while (i < 4)
//	{
//		buf[i] = buff[i];
//		i++;
//	}
////	buf[0] = 0x25;
////	buf[1] = 0x71;
////	buf[2] = 0x25;
////	buf[3] = 0x71;
//	i = ((buf[0] & 8) << 24) | ((buf[1] & 8) << 16) | ((buf[2] & 8) << 8) | (buf[3] & 8);
//	i = (buf[0] )
//	return (i);
//}