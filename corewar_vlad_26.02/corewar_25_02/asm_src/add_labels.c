/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_labels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:35:45 by bdomansk          #+#    #+#             */
/*   Updated: 2018/12/07 12:35:46 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	new_label(t_command *cmd, char *s, int *i)
{
	int		start;
	int		k;
	t_label *begin;
	t_label *new;

	start = *i;
	k = 0;
	while (s[*i] && s[*i] != LABEL_CHAR)
		(*i)++;
	begin = cmd->label;
	while (cmd->label && cmd->label->next)
		cmd->label = cmd->label->next;
	new = (t_label*)malloc(sizeof(t_label));
	new->next = NULL;
	new->name = (char*)malloc(*i - start + 1);
	while (start != *i)
		new->name[k++] = s[start++];
	new->name[k] = '\0';
	if (!begin)
		begin = new;
	else
		cmd->label->next = new;
	cmd->label = begin;
	(*i)++;
}

void		add_labels(t_asm *info, t_command *new, int *i)
{
	char	*s;
	int		start;

	while (info->line)
	{
		start = *i;
		if (is_contains_label(info->line, *i))
			new_label(new, info->line, i);
		if (is_contains_command(info->line, start))
			break ;
		if (!is_empty_line(info->line, i))
			error_reason(info, "Wrong text after label");
		ft_strdel(&info->line);
		get_next_line(info->fd, &info->line);
		*i = 0;
		info->num_line++;
		ignore_comment(info->line);
		s = info->line;
		while (s && (s[*i] == ' ' || s[*i] == '\t'))
			(*i)++;
	}
}
