/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binary_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:53:35 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/09 13:53:37 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_is_null(char *temp_null)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (temp_null[i])
			return (0);
		i++;
	}
	return (1);
}

void		check_binary_file(t_asm *info)
{
	char temp_null[4];

	if (!read(info->fd, &info->magic, 4))
		error_reason(info, "Magic header is missing");
	if (reverse(info->magic, 4) != COREWAR_EXEC_MAGIC)
		error_reason(info, "Wrong magic header");
	if (!read(info->fd, info->champion_name, PROG_NAME_LENGTH))
		error_reason(info, "Сhampion name is missing");
	if (!read(info->fd, temp_null, 4) || !check_is_null(temp_null))
		error_reason(info, "Null after champion name is missing");
	if (!read(info->fd, &info->prog_size, 4))
		error_reason(info, "Champion code size is missing");
	if (!read(info->fd, info->champion_comment, COMMENT_LENGTH))
		error_reason(info, "Champion comment is missing");
	if (!read(info->fd, temp_null, 4) || !check_is_null(temp_null))
		error_reason(info, "Null after champion comment is missing");
	info->prog_size = reverse(info->prog_size, 4);
}
