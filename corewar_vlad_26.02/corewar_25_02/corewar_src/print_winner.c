/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:15:15 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/25 18:15:16 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Нужно переименовать функцию. Если есть чемпион , то выводится его имя в
** формате как снизу, если чепион не был найден(dump или esc в визуализации)
** то просто проверяются лики
*/

void	print_winner(t_vm *vm)
{
	int id;

	if (vm->flags->c)
		ft_printf("%s", GREEN);
	if (vm->winner)
	{
		id = vm->winner->id;
		ft_printf("Contestant %d, \"%s\", has won!\n", id, vm->winner->name);
	}
	if (vm->flags->c)
		ft_printf("%s", DEF);
	if (vm->flags->l)
		system("leaks corewar");
	if (vm->flags->m)
		system("afplay music/Winning.mp3&");
}
