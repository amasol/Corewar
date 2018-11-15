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

void				processing_function(t_val *bot)
{
	t_val *tmp;
	int i;

	i = 0;
	tmp = bot;



	if (bot->executable_code[i] == 0xb)
		ft_sti(&bot->executable_code[i + 1]);

//	while (i < bot->b_size_int)
//		printf("%02hhx ", bot->executable_code[i++]);
//	printf("\n");
}
