/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_of_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:25:31 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/25 17:25:33 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	line_analysis(t_asm *info, char *str)
{
	char	*substr;
	int		i;

	if (str[ft_strlen(str) - 1] != '\n')
	{
		substr = ft_strrchr(str, '\n');
		ignore_comment(++substr);
		i = 0;
		if (!is_empty_line(substr, &i))
		{
			if (is_contains_label(substr, i) || is_contains_command(substr, i))
			{
				ft_strdel(&str);
				error_reason(info, "Wrong EOF. No new line after last command");
			}
		}
	}
}

void		check_end_of_file(t_asm *info)
{
	char *str;
	char *buf;
	char *res;

	str = ft_strnew(1);
	res = NULL;
	lseek(info->fd, -BUFF_SIZE, SEEK_CUR);
	while (!ft_strchr(str, '\n'))
	{
		buf = ft_strnew(BUFF_SIZE + 1);
		read(info->fd, buf, BUFF_SIZE);
		res = ft_strjoin(buf, str);
		ft_strdel(&str);
		ft_strdel(&buf);
		str = res;
		lseek(info->fd, -BUFF_SIZE * 2, SEEK_CUR);
	}
	line_analysis(info, res);
	ft_strdel(&str);
}
