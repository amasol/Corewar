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

// как приминмать от войда и кастаить в то что нам нужно
//  тут будет масив функций который будет опеределять в какой момент что выбрать
int				processing_function(t_val *bot, t_carriage *carriage)
{
	t_val 			*tmp;
	unsigned char	*ptr;
	int 			i;

	i = 0;
	tmp = bot;
//	printf("%d\n", carriage->position);




	if (bot->executable_code[i] == 0x1)
	{
		i += 1;
		ft_live(&bot->executable_code[i], carriage);
	}

	else if (bot->executable_code[i] == 0x2)
	{
		i += 1;
		ft_ld(&bot->executable_code[i], carriage);
	}
	/*
	else if (bot->executable_code[i] == 0x3)
	{
		i += 1;
		ft_st(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0x4)
	{
		i += 1;
		ft_add(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0x5)
	{
		i += 1;
		ft_sub(&bot->executable_code[i], carriage);
	}
*/
/*
	if (bot->executable_code[i] == 0x6)
	{
		i += 1;
		ft_and(&bot->executable_code[i], carriage);
	}

	else if (bot->executable_code[i] == 0x7)
	{
		i += 1;
		ft_or(&bot->executable_code[i], carriage);
	}
 */
	else if (bot->executable_code[i] == 0x8)
	{
		i += 1;
		ft_xor(&bot->executable_code[i], carriage);
	}
 /*
	else if (bot->executable_code[i] == 0x9)
	{
		i += 1;
		ft_zjmp(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0xa)
	{
		i += 1;
		ft_ldi(&bot->executable_code[i], carriage);
	}
*/
	else if (bot->executable_code[i] == 0xb)
	{
		printf("%d\n", i);
		printf("%02hhx %02hhx %02hhx %02hhx\n", bot->executable_code[0],
			   bot->executable_code[1],
			   bot->executable_code[2],
			   bot->executable_code[3]);
		i += ft_sti(bot->executable_code, carriage);
	}


/*
	else if (bot->executable_code[i] == 0xc)
	{
		i += 1;
		ft_fork(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0xd)
	{
		i += 1;
		ft_lld(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0xe)
	{
		i += 1;
		ft_lldi(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0xf)
	{
		i += 1;
		ft_lfork(&bot->executable_code[i], carriage);
	}
	else if (bot->executable_code[i] == 0x10)
	{
		i += 1;
		ft_aff(&bot->executable_code[i], carriage);
	}

*/





//			печать
//	while (i < bot->b_size_int)
//		printf("%02hhx ", bot->executable_code[i++]);
//	printf("\n");
	return (0);
}

//void		search_func(t_carriage *carriage)
//{
//
//}


//		пример
/*
#include <stdio.h>


void func1(void)
{
	printf("func1\n");
}

void func2(void)
{
	printf("func2\n");
}

void func3(void)
{
	printf("func3\n");
}

typedef struct functions
{
	void (*func)(void);
}               funcStruct;


int main(void)
{
	funcStruct f;
	f.func = &func1;
	f.func();

//    f.func = &func2;
//    f.func();
//
//    f.func = &func3;
//    f.func();

	return (0);
}
*/
