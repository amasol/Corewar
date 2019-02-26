/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:25:14 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/09 16:25:16 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_arg_type_dir(t_asm *info, t_command *cmd, int i)
{
	int				desired_type;
	unsigned int	buf;

	desired_type = g_operations[cmd->opcode - 1].type_args[i];
	if ((desired_type | T_DIR) != desired_type)
		error_reason(info, "Wrong argument type");
	if (!read(info->fd, &buf, g_operations[cmd->opcode - 1].dir_size))
		error_reason(info, "No argument");
	buf = reverse(buf, g_operations[cmd->opcode - 1].dir_size);
	cmd->arg[i].value = (int)buf;
	cmd->arg[i].type = T_DIR;
}

static void	get_arg_type_ind(t_asm *info, t_command *cmd, int i)
{
	int				desired_type;
	unsigned int	buf;

	desired_type = g_operations[cmd->opcode - 1].type_args[i];
	if ((desired_type | T_IND) != desired_type)
		error_reason(info, "Wrong argument type");
	if (!read(info->fd, &buf, IND_SIZE))
		error_reason(info, "No argument");
	buf = reverse(buf, IND_SIZE);
	cmd->arg[i].value = (int)buf;
	cmd->arg[i].type = T_IND;
}

static void	get_arg_type_reg(t_asm *info, t_command *cmd, int i)
{
	int				desired_type;
	unsigned char	buf;

	desired_type = g_operations[cmd->opcode - 1].type_args[i];
	if ((desired_type | T_REG) != desired_type)
		error_reason(info, "Wrong argument type");
	if (!read(info->fd, &buf, 1))
		error_reason(info, "No argument");
	cmd->arg[i].value = (int)buf;
	cmd->arg[i].type = T_REG;
}

void		get_arg_by_type(t_asm *info, t_command *cmd, int i, int type)
{
	if (type == T_DIR)
		get_arg_type_dir(info, cmd, i);
	else if (type == T_IND)
		get_arg_type_ind(info, cmd, i);
	else if (type == T_REG)
		get_arg_type_reg(info, cmd, i);
}
