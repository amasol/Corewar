/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:26:58 by bdomansk          #+#    #+#             */
/*   Updated: 2018/12/05 15:27:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_command	*new_command(t_asm *info)
{
	t_command	*start;
	t_command	*new;

	start = info->command;
	while (info->command && info->command->next)
		info->command = info->command->next;
	new = (t_command*)malloc(sizeof(t_command));
	new->opcode = 0;
	new->size = 0;
	new->size_before = 0;
	new->argument_type_code = 0;
	new->label = NULL;
	new->name = NULL;
	new->next = NULL;
	new->args = NULL;
	if (!start)
		start = new;
	else
		info->command->next = new;
	info->command = start;
	return (new);
}
