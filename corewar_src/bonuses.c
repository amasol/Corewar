/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:17:57 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 12:17:59 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Нужно переименовать функцию. Если есть чемпион , то выводится его имя в
** формате как снизу, если чепион не был найден(dump или esc в визуализации)
** то просто проверяются лики
*/

void	bonuses(t_vm *info)
{
	if (info->flags->c)
		ft_printf("%s", GREEN);
	ft_printf("Contestant n, %s, has won!\n", "champ_name");
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks corewar");
	if (info->flags->m)
		system("afplay music/Winning.mp3&");
}
