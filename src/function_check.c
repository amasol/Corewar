/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:13:29 by amasol            #+#    #+#             */
/*   Updated: 2018/11/13 15:13:34 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

// 1)	написать бота с минимальным набором операций
// 2)	op_tab -> реализовать!

t_func				g_funclist[FNUM] =
{
	{0x1, ft_live},
	{0x2, ft_ld},
	{0x3, ft_st},
	{0x4, ft_add},
	{0x5, ft_sub},
	{0x6, ft_and},
	{0x7, ft_or},
	{0x8, ft_xor},
	{0x9, ft_zjmp},
	{0xA, ft_ldi},
	{0xB, ft_sti},
	{0xC, ft_fork},
	{0xD, ft_lld},
	{0xE, ft_lldi},
	{0xF, ft_lfork},
	{0x10, ft_aff}
};

void				processing_function(t_bot *bot, t_carriage *carriage)
{
	int i = -1;
	int j = 0;
//	while (++j < bot->b_size_int)
//	{
//		i = -1;
		while (++i < FNUM)
			if (bot->exec_code[j] == g_funclist[i].command)
				(g_funclist[i].fptr)(&bot->exec_code[i], carriage);
//	}
}

/* // пример как было
	if (bot->executable_code[i] == 0xa)
	{
		i += 1;
		ft_ldi(&bot->executable_code[i], carriage);
	}
*/
// 	else if (bot->executable_code[i] == 0xb)
// 	{
// //		printf("%d\n", i);
// //		printf("%02hhx %02hhx %02hhx %02hhx\n", bot->executable_code[0],
// //			   bot->executable_code[1],
// //			   bot->executable_code[2],
// //			   bot->executable_code[3]);
// 		i += ft_sti(bot->executable_code, carriage);
// 	}


//			печать
//	while (i < bot->b_size_int)
//		printf("%02hhx ", bot->executable_code[i++]);
//	printf("\n");
// 	return (0);
// }

//void		search_func(t_carriage *carriage)
//{
//
//}

