/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:29:03 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/03 18:29:06 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	find_name(t_command *cmd, char *s, int *i)
{
	if (is_contains_label(s, *i))
	{
		while (s[*i] != LABEL_CHAR)
			(*i)++;
		(*i)++;
	}
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	cmd->opcode = find_opcode(s, *i);
	cmd->name = g_operations[cmd->opcode - 1].name;
	(*i) = (*i) + ft_strlen(cmd->name);
}

static void	get_arguments(t_asm *info, t_command *cmd, int *i)
{
	int number;

	cmd->args = ft_strsplit(info->line + *i, SEPARATOR_CHAR);
	trim_arguments(cmd->args);
	if (!cmd->args || !cmd->args[0])
		error_reason(info, "Command without arguments");
	number = array_len(cmd->args);
	if (number > 3)
		error_reason(info, "Command contains too many arguments");
	if (number - 1 < character_count(SEPARATOR_CHAR, info->line + *i))
		error_reason(info, "Command contains too many separator characters");
	if (number != g_operations[cmd->opcode - 1].number_args)
		error_reason(info, "Wrong number of arguments for current command");
}

static void	check_arguments(t_asm *info, t_command *cmd)
{
	int i;
	int type;
	int	desired_type;

	i = 0;
	while (cmd->args && cmd->args[i])
	{
		type = get_type(cmd->args[i]);
		desired_type = g_operations[cmd->opcode - 1].type_args[i];
		if (!type)
			error_reason(info, ft_strjoin("Unrecognized argument type: ",
			cmd->args[i]));
		if ((desired_type | type) != desired_type)
			error_reason(info, ft_strjoin("Wrong argument type: ",
			cmd->args[i]));
		cmd->arg[i].type = type;
		cmd->arg[i].content = cmd->args[i];
		i++;
	}
}

void		parse_command(t_asm *info, t_command *cmd, int *i)
{
	find_name(cmd, info->line, i);
	get_arguments(info, cmd, i);
	check_arguments(info, cmd);
	analyze_arguments(cmd);
}
