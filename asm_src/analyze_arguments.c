/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:30:03 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/22 16:30:05 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_arg_contnet(t_command *cmd, int i)
{
	char	*temp;
	int		start;

	start = (*cmd->arg[i].content == DIRECT_CHAR) ? 2 : 1;
	temp = ft_strdup(cmd->arg[i].content + start);
	ft_strdel(&cmd->arg[i].content);
	cmd->arg[i].content = temp;
}

static void	get_arg_value(t_command *cmd, int i)
{
	char *content;

	content = cmd->arg[i].content;
	if (cmd->arg[i].type == T_REG)
	{
		cmd->arg[i].value = ft_atoi(content + 1);
		cmd->arg[i].flag = FLAG_VALUE;
	}
	else
	{
		if (*content == DIRECT_CHAR)
			content++;
		if (*content == LABEL_CHAR)
		{
			get_arg_contnet(cmd, i);
			cmd->arg[i].flag = FLAG_STRING;
		}
		else
		{
			cmd->arg[i].value = ft_atoi(content);
			cmd->arg[i].flag = FLAG_VALUE;
		}
	}
}

static void	get_arg_size(t_command *cmd, int i)
{
	if (cmd->arg[i].type == T_REG)
		cmd->arg[i].size = 1;
	else if (cmd->arg[i].type == T_IND)
		cmd->arg[i].size = IND_SIZE;
	else
		cmd->arg[i].size = g_operations[cmd->opcode - 1].dir_size;
}

void		analyze_arguments(t_command *cmd)
{
	int i;

	i = 0;
	while (i < g_operations[cmd->opcode - 1].number_args)
	{
		get_arg_value(cmd, i);
		get_arg_size(cmd, i);
		i++;
	}
}
