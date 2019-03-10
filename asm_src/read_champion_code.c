/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champion_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:15:06 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/09 14:15:08 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_type_of_arguments(t_asm *info, t_command *cmd)
{
	int i;
	int	type_code;

	i = 0;
	type_code = cmd->argument_type_code;
	while (i < g_operations[cmd->opcode - 1].number_args)
	{
		if (!(type_code & 128) && (type_code & 64))
			get_arg_by_type(info, cmd, i, T_REG);
		else if ((type_code & 128) && !(type_code & 64))
			get_arg_by_type(info, cmd, i, T_DIR);
		else if ((type_code & 128) && (type_code & 64))
			get_arg_by_type(info, cmd, i, T_IND);
		else
			error_reason(info, "Wrong argument");
		i++;
		type_code <<= 2;
	}
}

void		read_champion_code(t_asm *info)
{
	unsigned char	byte;
	int				arg_type_code;
	t_command		*cmd;

	while (read(info->fd, &byte, 1))
	{
		cmd = new_command(info);
		cmd->opcode = (int)byte;
		arg_type_code = g_operations[cmd->opcode - 1].code_type;
		if (arg_type_code && !read(info->fd, &byte, 1))
			error_reason(info, "No argumet type code after command");
		if (arg_type_code)
		{
			cmd->argument_type_code = (int)byte;
			check_type_of_arguments(info, cmd);
		}
		if (!arg_type_code)
			get_arg_by_type(info, cmd, 0, T_DIR);
	}
}
