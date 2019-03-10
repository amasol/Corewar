/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bots_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:50:02 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/17 17:50:03 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	swap_bots(t_vm *info, int num)
{
	t_bot temp_bot;

	temp_bot = info->bot[num];
	info->bot[num] = info->bot[num + 1];
	info->bot[num + 1] = temp_bot;
}

static void	sort_bots_by_id(t_vm *info)
{
	int i;
	int j;

	i = 0;
	while (i + 1 < info->number_of_bots)
	{
		j = 0;
		while (j + 1 < info->number_of_bots)
		{
			if (info->bot[j].id > info->bot[j + 1].id)
				swap_bots(info, j);
			j++;
		}
		i++;
	}
}

void		define_bots_id(t_vm *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->number_of_bots)
	{
		if (info->bot[i].id == 0)
		{
			j = 1;
			while (info->available_id[j])
				j++;
			info->available_id[j] = 1;
			info->bot[i].id = j;
		}
		i++;
	}
	if (info->flags->n)
		sort_bots_by_id(info);
	info->last_live_bot = &info->bot[info->number_of_bots - 1];
}
