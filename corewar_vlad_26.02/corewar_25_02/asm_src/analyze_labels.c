/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:10:19 by bdomansk          #+#    #+#             */
/*   Updated: 2019/01/26 16:10:21 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_value_of_label(t_asm *info, t_command *cmd, int i)
{
	t_command	*temp;
	t_label		*label;

	temp = info->command;
	while (temp)
	{
		label = temp->label;
		while (label)
		{
			if (!ft_strcmp(cmd->arg[i].content, label->name))
			{
				cmd->arg[i].flag = FLAG_VALUE;
				cmd->arg[i].value = temp->size_before - cmd->size_before;
				return ;
			}
			label = label->next;
		}
		temp = temp->next;
	}
	error_reason(info, ft_strjoin("Wrong label name: ", cmd->arg[i].content));
}

void		analyze_labels(t_asm *info)
{
	int			i;
	int			len;
	t_command	*temp;

	temp = info->command;
	while (temp)
	{
		i = 0;
		len = g_operations[temp->opcode - 1].number_args;
		while (i < len)
		{
			if (temp->arg[i].flag == FLAG_STRING)
				get_value_of_label(info, temp, i);
			i++;
		}
		temp = temp->next;
	}
}
