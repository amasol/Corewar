/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:27:37 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/18 14:27:39 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_bot(t_vm *info, int num_recorded_bots, int *i)
{
	unsigned char	*exec_code;
	int				temp;
	int				size;

	size = info->bot[num_recorded_bots].prog_size;
	temp = size;
	exec_code = info->bot[num_recorded_bots].exec_code;
	while (temp > 0)
	{
		info->map[*i].cell = exec_code[size - temp];
		info->map[*i].color = info->bot[num_recorded_bots].id;
		info->map[*i].temp_color = 0;
		info->map[*i].cycles = 0;
		(*i)++;
		temp--;
	}
}

void		fill_map(t_vm *info)
{
	int i;
	int	num_recorded_bots;

	i = 0;
	num_recorded_bots = 0;
	while (i < MEM_SIZE)
	{
		if (i == num_recorded_bots * MEM_SIZE / info->number_of_bots)
		{
			new_carriage(info, &info->bot[num_recorded_bots], i);
			put_bot(info, num_recorded_bots, &i);
			num_recorded_bots++;
		}
		info->map[i].cell = 0;
		info->map[i].color = 10;
		info->map[i].temp_color = 0;
		info->map[i].cycles = 0;
		i++;
	}
}
