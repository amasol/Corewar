/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_carriages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:54 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/24 14:02:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Если в каретке еще не сохраненна команда, а место на котором стоит каретка
** содержит не коректную команду, то каретка передвигается на 1 шаг вперед.
** Иначе, если команда еще не записана, то записываев в каретку команду и
** количество циклов, которое картке нужно ожидать выполения команды.
** Уменьшаем количество циклов ожидания.
** Если количесвто циклов ожидания равно 0, то мы выполняем команду,
** передвигаем каретку, и убираем записаную команду из каретки.
** В этом коментарии команда употреблялась в значении opcode.
*/

static void	perform_carriage(t_carriage *carr, t_vm *vm)
{
	int			pos;

	pos = carr->position;
	if (!carr->exec_cmd && (vm->map[pos].cell > 16 || !vm->map[pos].cell))
		carr->position = (pos + 1) % MEM_SIZE;
	else
	{
		if (!carr->exec_cmd)
		{
			carr->exec_cmd = OPCODE(vm->map[pos].cell);
			carr->cycles_left = CYCLES(carr->exec_cmd);
		}
		if (carr->cycles_left > 0)
			carr->cycles_left--;
		if (carr->cycles_left == 0)
		{
			// ft_live(carr, vm);
			// ft_zjmp(carr, vm);
			ft_printf("Выполняем cmd %d, двигаем каретку\n", carr->exec_cmd);
			g_operations[carr->exec_cmd - 1].function(vm, carr);
			carr->exec_cmd = 0;
		}
	}
}

void		perform_carriages(t_vm *vm)
{
	t_carriage	*start;

	start = vm->carriage;
	while (vm->carriage)
	{
		perform_carriage(vm->carriage, vm);
		vm->carriage = vm->carriage->next;
	}
	vm->carriage = start;
}

