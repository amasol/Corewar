/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carriages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:49:59 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/25 13:50:01 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Увеличиваем число проведенных подряд проверок. Проводим проверку всех
** кареток, и удаляем все те каретки, которые не выполняли операцию live
** за последние vm->cycle_to_die циклов. Eсли общее количество выполненых
** операций live за последний период больше NBR_LIVE или если количество
** проведеных подряд проверок равно 10, то мы обнуляем числов проверок и
** уменьшаем значение vm->cycle_to_die на CYCLE_DELTA. Обновляем количесвто
** операций live для каждого бота, а также общее количество выполеных
** операций за последний период. Определяем следующий цикл, в котором
** будет произведенна проверка.
*/

static void	show_deaths(t_vm *vm, t_carriage *carriage)
{
	int	cycles;

	cycles = vm->current_cycle - carriage->cycle_last_live;
	ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
	carriage->id, cycles, vm->cycle_to_die);
}

static void	free_carriages(t_vm *vm)
{
	t_carriage	*previous;
	t_carriage	*current;
	t_carriage	*temp;

	previous = NULL;
	current = vm->carriage;
	while (current)
		if (!current->alive)
		{
			vm->current_num_of_carriages--;
			temp = current;
			current = current->next;
			vm->carriage = (!previous) ? current : vm->carriage;
			if (previous)
				previous->next = current;
			if (!vm->flags->v && vm->flags->deaths)
				show_deaths(vm, temp);
			free(temp);
		}
		else
		{
			previous = current;
			current->alive = 0;
			current = current->next;
		}
}

static void	update_lives_period(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->number_of_bots)
	{
		vm->previous_lives[i] = vm->current_lives[i];
		vm->bot[i].lives_current_period = 0;
		i++;
	}
	vm->number_of_lives = 0;
}

void		check_carriages(t_vm *vm)
{
	vm->number_of_checks++;
	free_carriages(vm);
	if (vm->number_of_lives >= NBR_LIVE || vm->number_of_checks == MAX_CHECKS)
	{
		vm->number_of_checks = 0;
		vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	}
	update_lives_period(vm);
	if (vm->cycle_to_die > 0)
		vm->cycle_check = vm->current_cycle + vm->cycle_to_die;
	else
		vm->cycle_check = vm->current_cycle + 1;
}
