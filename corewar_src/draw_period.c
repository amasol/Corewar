/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_period.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:23:16 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 17:23:18 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	find_max(t_vm *vm)
{
	int		i;
	int		max;

	max = 0;
	i = -1;
	while (++i < vm->number_of_bots)
	{
		if (vm->bot[max].lives_current_period < vm->bot[i].lives_current_period)
			max = i;
	}
	return (max);
}

static int	sum_bot_lives(t_vm *vm)
{
	int		live_sum;
	int		i;

	i = -1;
	live_sum = 0;
	while (++i < vm->number_of_bots)
	{
		live_sum += vm->bot[i].lives_current_period;
	}
	return (live_sum);
}

static void	print_previous(t_vm *vm)
{
	int		i;
	int		j;
	int		n;
	int		prev[4];

	i = -1;
	j = 0;
	n = (vm->number_of_bots * 6) + 2;
	prev[0] = vm->previous_lives[0];
	prev[1] = vm->previous_lives[1];
	prev[2] = vm->previous_lives[2];
	prev[3] = vm->previous_lives[3];
	while (++i < vm->number_of_bots)
	{
		while (prev[i]--)
		{
			wattron(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
			mvwprintw(vm->info, n + 6, 4 + j, " ");
			wattroff(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
			j++;
		}
	}
}

static void	calculate_period(t_vm *vm, int n, int i)
{
	int		percent_sum;
	int		max;
	int		j;
	float	percent[4];

	while (++i < 4)
		percent[i] = (i < vm->number_of_bots) ? vm->current_lives[i] : 0;
	i = -1;
	j = 0;
	percent_sum = percent[0] + percent[1] + percent[2] + percent[3];
	max = find_max(vm);
	percent[max] += 50 - percent_sum;
	vm->current_lives[max] += 50 - percent_sum;
	while (++i < vm->number_of_bots)
	{
		while (percent[i]--)
		{
			wattron(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
			mvwprintw(vm->info, n + 3, 4 + j, " ");
			wattroff(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
			j++;
		}
	}
}

void		draw_period(t_vm *vm)
{
	int		n;
	int		i;
	int		live_sum;

	n = (vm->number_of_bots * 6) + 2;
	live_sum = sum_bot_lives(vm);
	i = -1;
	if (live_sum)
	{
		while (++i < vm->number_of_bots)
		{
			vm->current_lives[i] = (vm->bot[i].lives_current_period * 100)
			/ live_sum;
			vm->current_lives[i] = (int)((50 * vm->current_lives[i]) / 100);
			if (!vm->current_lives[i] && vm->bot[i].lives_current_period)
				vm->current_lives[i] = 1;
		}
		calculate_period(vm, n, -1);
	}
	print_previous(vm);
}
