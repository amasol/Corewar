/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:41:40 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/13 17:41:41 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

static void	check_binary_file(t_vm *info)
{
	unsigned int	magic;
	char			temp_null[4];
	int				i;

	i = info->number_of_bots;
	if (!read(info->fd, &magic, 4))
		error_reason(info, "Magic header is missing");
	if (reverse(magic, 4) != COREWAR_EXEC_MAGIC)
		error_reason(info, "Wrong magic header");
	if (!read(info->fd, info->bot[i].name, PROG_NAME_LENGTH))
		error_reason(info, "Сhampion name is missing");
	if (!read(info->fd, temp_null, 4) || !check_is_null(temp_null))
		error_reason(info, "Null after champion name is missing");
	if (!read(info->fd, &info->bot[i].prog_size, 4))
		error_reason(info, "Champion code size is missing");
	info->bot[i].prog_size = reverse(info->bot[i].prog_size, 4);
	if (info->bot[i].prog_size > CHAMP_MAX_SIZE)
		error_reason(info, "Code size is bigger then CHAMP_MAX_SIZE");
	if (!read(info->fd, info->bot[i].comment, COMMENT_LENGTH))
		error_reason(info, "Champion comment is missing");
	if (!read(info->fd, temp_null, 4) || !check_is_null(temp_null))
		error_reason(info, "Null after champion comment is missing");
}

static void	check_file_name(t_vm *info, int *i)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(info->argv[*i], '.');
	fd = open(info->argv[*i], O_RDONLY);
	if (fd < 0)
		info->error_reason = "Cant open this file";
	else if (!extension)
		info->error_reason = "Name of the file without any extension";
	else if (ft_strcmp(extension, ".cor"))
		info->error_reason = "Extension of file must be .cor";
	else if (read(fd, NULL, 0) == -1)
		info->error_reason = "Cant read this file";
	if (info->error_reason)
		put_manual(info);
	info->fd = fd;
}

static void	check_exec_code(t_vm *info)
{
	int				i;
	char			temp;
	unsigned int	prog_size;

	i = info->number_of_bots;
	prog_size = info->bot[i].prog_size;
	info->bot[i].exec_code = (unsigned char*)malloc(prog_size + 1);
	if (read(info->fd, info->bot[i].exec_code, prog_size) != prog_size)
		error_reason(info, "Bot's code size differ from what its header says");
	if (read(info->fd, &temp, 1))
		error_reason(info, "Bot's code size differ from what its header says");
}

void		check_bot(t_vm *info, int *i)
{
	if (info->number_of_bots >= MAX_PLAYERS)
	{
		info->error_reason = "Too many bots. Maximum allowed only four";
		put_manual(info);
	}
	check_file_name(info, i);
	check_binary_file(info);
	check_exec_code(info);
	info->bot[info->number_of_bots].lives_current_period = 0;
	info->bot[info->number_of_bots].cycle_last_live = 0;
	info->number_of_bots++;
	(*i)++;
}
