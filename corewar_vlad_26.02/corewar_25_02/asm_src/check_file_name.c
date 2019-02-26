/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:36:58 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/09 11:37:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_new_name(t_asm *info, char *extension)
{
	int		len;
	char	*new;
	char	*new_extension;

	new_extension = (info->flags->d) ? ".s" : ".cor";
	if (info->flags->i && ft_strrchr(info->file_name, '/'))
		info->file_name = ft_strrchr(info->file_name, '/') + 1;
	len = ft_strlen(info->file_name) - ft_strlen(extension);
	new = ft_strnew(len);
	new = ft_strncpy(new, info->file_name, len);
	info->new_file_name = ft_strjoin(new, new_extension);
	ft_strdel(&new);
}

void		check_file_name(t_asm *info)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(info->file_name, '.');
	fd = open(info->file_name, O_RDONLY);
	if (fd < 0)
		info->error_reason = "Cant open this file";
	else if (!extension)
		info->error_reason = "Name of the file without any extension";
	else if (info->flags->d && ft_strcmp(extension, ".cor"))
		info->error_reason = "For flag -d extension of file must be .cor";
	else if (!info->flags->d && ft_strcmp(extension, ".s"))
		info->error_reason = "Extension of file must be .s";
	else if (read(fd, NULL, 0) == -1)
		info->error_reason = "Cant read this file";
	if (info->error_reason)
		error(info);
	get_new_name(info, extension);
	info->fd = fd;
}
