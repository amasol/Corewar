/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champion_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:34:23 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/09 17:34:24 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	print_header(t_asm *info)
{
	char *comment;

	comment = info->champion_comment;
	write(info->new_fd, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING));
	write(info->new_fd, " \"", 2);
	write(info->new_fd, info->champion_name, ft_strlen(info->champion_name));
	write(info->new_fd, "\"\n", 2);
	write(info->new_fd, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING));
	write(info->new_fd, " \"", 2);
	write(info->new_fd, comment, ft_strlen(comment));
	write(info->new_fd, "\"\n\n", 3);
}

static void	print_cmd(t_command *cmd, int fd)
{
	int		i;
	char	*name;

	i = 0;
	name = g_operations[cmd->opcode - 1].name;
	write(fd, "\t", 1);
	write(fd, name, ft_strlen(name));
	write(fd, "\t", 1);
	while (i < g_operations[cmd->opcode - 1].number_args)
	{
		if (cmd->arg[i].type == T_REG)
			write(fd, "r", 1);
		else if (cmd->arg[i].type == T_DIR)
			write(fd, "%", 1);
		ft_putnbr_fd(cmd->arg[i].value, fd);
		i++;
		if (i < g_operations[cmd->opcode - 1].number_args)
			write(fd, ", ", 2);
	}
	write(fd, "\n", 1);
}

void		print_champion_file(t_asm *info)
{
	t_command *start;

	print_header(info);
	start = info->command;
	while (info->command)
	{
		print_cmd(info->command, info->new_fd);
		info->command = info->command->next;
	}
	info->command = start;
}
