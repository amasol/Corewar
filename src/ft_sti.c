/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:52:16 by amasol            #+#    #+#             */
/*   Updated: 2018/11/14 16:52:17 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

t_arr				get_cod(char c)
{
	int 	i;
	t_arr	arr;

	i = 0;
	while (i < 3)
	{
		if ((c >> (6 - 2 * i) & 3) == REG_CODE)
			arr[i] = T_REG;
		else if ((c >> (6 - 2 * i) & 3) == DIR_CODE)
			arr[i] = T_DIR;
		else if ((c >> (6 - 2 * i) & 3) == IND_CODE)
			arr[i] = T_IND;
		++i;
	}
	return (arr);
}

void				ft_sti(unsigned char *codage)
{
	t_arr cod;

	int i;

	 i = 0;
	cod = get_cod(codage[i]);

//	printf("%d\n", cod[0]); // находиться наше кол-во байт
	printf("%02hhx\n", cod[1]);
//	printf("%d\n", cod[1]);
//	printf("%d\n", cod[2]);

//	while (i < 10)
//		printf("%02hhx ", codage[i++]);
//	printf("\n");


}



/*
void				ft_sti(unsigned char *codage)
{
	int i;

	i = 0;
	if ((codage[i] >> 6) & 3 == REG_CODE)
		T_REG...;
	if ((codage[i] >> 6) & 3 == DIR_CODE)
		T_DIR...;
	if ((codage[i] >> 6) & 3 == IND_CODE)
		T_IND...;
	{
	}

	if ((codage[i] >> 4) & 3 == REG_CODE)
		T_REG...;
	if ((codage[i] >> 4) & 3 == DIR_CODE)
		T_DIR...;
	if ((codage[i] >> 4) & 3 == IND_CODE)
		T_IND...;
}
*/


