/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:07:18 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/13 18:07:22 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	skip_spases(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
}

static void	add_champion_name(t_asm *info, int *i)
{
	int		j;
	char	*line;

	j = 0;
	line = info->line;
	while (line)
	{
		while (line[*i] && line[*i] != '\"' && j < PROG_NAME_LENGTH)
			info->champion_name[j++] = line[(*i)++];
		if (line[*i] && line[*i] == '\"')
			break ;
		else if (j < PROG_NAME_LENGTH)
			info->champion_name[j++] = '\n';
		else
			error_reason(info, "Too big champion name");
		ft_strdel(&line);
		get_next_line(info->fd, &line);
		info->num_line = (line) ? info->num_line + 1 : info->num_line;
		*i = 0;
	}
	info->line = line;
}

static void	add_champion_comment(t_asm *info, int *i)
{
	int		j;
	char	*line;

	j = 0;
	line = info->line;
	while (line)
	{
		while (line[*i] && line[*i] != '\"' && j < COMMENT_LENGTH)
			info->champion_comment[j++] = line[(*i)++];
		if (line[*i] && line[*i] == '\"')
			break ;
		else if (j < COMMENT_LENGTH)
			info->champion_name[j++] = '\n';
		else
			error_reason(info, "Too big champion comment");
		ft_strdel(&line);
		get_next_line(info->fd, &line);
		info->num_line = (line) ? info->num_line + 1 : info->num_line;
		*i = 0;
	}
	info->line = line;
}

void		get_champion_name(t_asm *info, int *flag_name)
{
	int i;

	(*flag_name) ? error_reason(info, "More than one champion name") : 0;
	*flag_name = 1;
	i = 0;
	skip_spases(info->line, &i);
	i = i + ft_strlen(NAME_CMD_STRING);
	skip_spases(info->line, &i);
	if (!info->line[i] || (info->line[i] && info->line[i++] != '\"'))
		error_reason(info, "Can't find \" before champion name");
	add_champion_name(info, &i);
	if (!info->line || (info->line[i] && info->line[i++] != '\"'))
		error_reason(info, "Can't find \" after champion name");
	skip_spases(info->line, &i);
	if (info->line && info->line[i] && info->line[i] != COMMENT_CHAR &&
		info->line[i] != SECOND_COMMENT_CHAR)
		error_reason(info, "Wrong text after champion name");
}

void		get_champion_comment(t_asm *info, int *flag_comment)
{
	int i;

	(*flag_comment) ? error_reason(info, "Second champion comment") : 0;
	*flag_comment = 1;
	i = 0;
	skip_spases(info->line, &i);
	i = i + ft_strlen(COMMENT_CMD_STRING);
	skip_spases(info->line, &i);
	if (!info->line[i] || (info->line[i] && info->line[i++] != '\"'))
		error_reason(info, "Can't find \" before champion comment");
	add_champion_comment(info, &i);
	if (!info->line || (info->line[i] && info->line[i++] != '\"'))
		error_reason(info, "Can't find \" after champion comment");
	skip_spases(info->line, &i);
	if (info->line && info->line[i] && info->line[i] != COMMENT_CHAR &&
		info->line[i] != SECOND_COMMENT_CHAR)
		error_reason(info, "Wrong text after champion champion");
}
