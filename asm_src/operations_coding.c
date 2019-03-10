/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_coding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:21:17 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/26 11:21:19 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_argument_type_code(t_command *cmd)
{
	int	code;
	int	len;
	int	i;

	if (g_operations[cmd->opcode - 1].code_type)
	{
		code = 0;
		len = g_operations[cmd->opcode - 1].number_args;
		i = 0;
		while (i < len)
		{
			code = (cmd->arg[i].type == T_REG) ? code | 1 : code;
			code = (cmd->arg[i].type == T_DIR) ? code | 2 : code;
			code = (cmd->arg[i].type == T_IND) ? code | 3 : code;
			code = code << 2;
			i++;
		}
		code = code << ((3 - len) * 2);
		cmd->argument_type_code = code;
	}
}

static void	get_command_size(t_command *cmd)
{
	int len;
	int i;

	cmd->size = 1;
	if (g_operations[cmd->opcode - 1].code_type)
		cmd->size++;
	len = g_operations[cmd->opcode - 1].number_args;
	i = 0;
	while (i < len)
	{
		cmd->size = cmd->size + cmd->arg[i].size;
		i++;
	}
}

void		operations_coding(t_asm *info)
{
	t_command *start;

	start = info->command;
	while (info->command)
	{
		if (info->command->name)
		{
			get_argument_type_code(info->command);
			get_command_size(info->command);
		}
		if (info->command->next)
			info->command->next->size_before = info->command->size_before +
		info->command->size;
		else
			info->prog_size = info->command->size_before + info->command->size;
		info->command = info->command->next;
	}
	info->command = start;
}
