/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:16:03 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/13 14:16:05 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

static int	is_champion_name(char *line)
{
	int	len;

	if (line)
	{
		len = ft_strlen(NAME_CMD_STRING);
		while (line && (*line == ' ' || *line == '\t'))
			line++;
		if (!ft_strncmp(line, NAME_CMD_STRING, len))
			return (1);
	}
	return (0);
}

static int	is_champion_comment(char *line)
{
	int	len;

	if (line)
	{
		len = ft_strlen(COMMENT_CMD_STRING);
		while (line && (*line == ' ' || *line == '\t'))
			line++;
		if (!ft_strncmp(line, COMMENT_CMD_STRING, len))
			return (1);
	}
	return (0);
}

static void	is_comment(t_asm *info)
{
	char	c1;
	char	c2;
	int		i;
	char	*line;

	i = 0;
	line = info->line;
	if (line[i])
	{
		c1 = COMMENT_CHAR;
		c2 = SECOND_COMMENT_CHAR;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] && ft_strlen(line) && line[i] != c1 && line[i] != c2)
		{
			info->error_reason = ft_strjoin("Wrong line between champion \
name and champion comment : ", line);
			error(info);
		}
	}
}

static void	is_no_name_or_comment(t_asm *info, int flag_n, int flag_c)
{
	if (!flag_n)
		info->error_reason = "There is no champion name in the file";
	else if (!flag_c)
		info->error_reason = "There is no champion comment in the file";
	if (info->error_reason)
		error(info);
}

void		check_name_and_comment(t_asm *info)
{
	int		flag_name;
	int		flag_comment;

	flag_comment = 0;
	flag_name = 0;
	while ((!flag_name || !flag_comment) &&
		get_next_line(info->fd, &info->line) > 0)
	{
		info->num_line++;
		if (is_champion_name(info->line))
			get_champion_name(info, &flag_name);
		else if (is_champion_comment(info->line))
			get_champion_comment(info, &flag_comment);
		else
			is_comment(info);
		ft_strdel(&info->line);
	}
	ft_strdel(&info->line);
	is_no_name_or_comment(info, flag_name, flag_comment);
}
