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

void				processing_function(t_val *bot, t_carriage *carriage)
{
	t_val *tmp;
	int i;
	unsigned char	*ptr;

	i = 0;
	tmp = bot;
	carriage->position = 0;
	if (bot->executable_code[i] == 0xb)
	{
//		carriage->position++;
		i += 1;
//		ft_sti(bot, carriage);
	}
	else if (bot->executable_code[i] == 0x6)
	{
//		carriage->position++;
		i++;
//		ft_and(bot, carriage);
	}

//	while (i < bot->b_size_int)
//		printf("%02hhx ", bot->executable_code[i++]);
//	printf("\n");
}
