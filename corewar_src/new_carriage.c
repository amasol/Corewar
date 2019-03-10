/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:57:09 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/19 15:57:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_registers(t_carriage *new)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->registers[i] = 0;
		i++;
	}
}

void		new_carriage(t_vm *info, t_bot *parent, int position)
{
	t_carriage *new;

	if (!(new = malloc(sizeof(t_carriage))))
		error_reason(info, "Memory was not allocated");
	info->num_of_carriages++;
	info->current_num_of_carriages++;
	new->id = info->num_of_carriages;
	new->position = position;
	new->carry = 0;
	new->opcode = 0;
	new->cycles_left = 0;
	new->parent = parent;
	new->number_of_arguments = 0;
	new->cycle_last_live = 0;
	new->alive = 0;
	new->next = NULL;
	init_registers(new);
	new->registers[1] = -parent->id;
	if (info->carriage)
		new->next = info->carriage;
	info->carriage = new;
}
