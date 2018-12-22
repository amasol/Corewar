/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:05:39 by amasol            #+#    #+#             */
/*   Updated: 2018/12/20 18:05:41 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"


t_arr				get_cod(char c)
{
	int 	i;
	t_arr	arr;
//
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

void	ft_add(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_add\n");
}

void	ft_aff(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_aff\n");
}

void	ft_and(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_and\n");
}

void	ft_fork(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_fork\n");
}

void	ft_ld(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_ld\n");
}

void	ft_ldi(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_ldi\n");
}

void	ft_lfork(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_lfork\n");
}

void	ft_live(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_live\n");
}

void	ft_lld(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_lld\n");
}

void	ft_lldi(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_lldi\n");
}

void	ft_or(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_or\n");
}

void	ft_st(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_st\n");
}

void	ft_sti(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_sti\n");
	t_arr	cod;
	int		i;
	int 	tmp[3];
//
	i = carriage->position + 1;
	//	здесь знаю кол-во считаных байт, но дальше мне
	// нужно использовать эти данный для отработки функции ...
	cod = get_cod(codage[i]);
	++i;
	if (cod[0] == REG_CODE)
		tmp[0] = carriage->register_id[codage[i]];
	//	или
	//	++i;
	//	if (cod[0] == T_REG)
	//	carriage->register_id[3] = cod[0];
//


	printf("%d\n", cod[0]);
	printf("%d\n", cod[1]);
	printf("%d\n", cod[2]);
}

void	ft_sub(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_sub\n");
}

void	ft_xor(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_xor\n");
}

void	ft_zjmp(unsigned char *codage, t_carriage *carriage)
{
	printf("ft_zjmp\n");
}
