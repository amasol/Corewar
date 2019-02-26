/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:06:48 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 14:06:50 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->h = 0;
	flags->l = 0;
	flags->c = 0;
	flags->d = 0;
	flags->m = 0;
	flags->i = 0;
	flags->n = 0;
	flags->exists = 0;
	return (flags);
}

static void		check_flags(t_asm *info, char *s)
{
	int i;

	if (s[0] == '-')
	{
		i = 1;
		while (s[i])
		{
			if (!ft_strchr("hlcdmin", (int)s[i]))
			{
				info->error_reason = ft_strjoin("wrong flags : ", s);
				put_manual(info);
			}
			info->flags->h = (s[i] == 'h') ? 1 : info->flags->h;
			info->flags->l = (s[i] == 'l') ? 1 : info->flags->l;
			info->flags->c = (s[i] == 'c') ? 1 : info->flags->c;
			info->flags->d = (s[i] == 'd') ? 1 : info->flags->d;
			info->flags->m = (s[i] == 'm') ? 1 : info->flags->m;
			info->flags->i = (s[i] == 'i') ? 1 : info->flags->i;
			info->flags->n = (s[i] == 'n') ? 1 : info->flags->n;
			i++;
		}
		info->flags->exists = 1;
	}
}

t_asm			*init_info(int argc, char **argv)
{
	t_asm	*info;

	info = (t_asm*)malloc(sizeof(t_asm));
	info->flags = init_flags();
	info->error_reason = NULL;
	if (argc > 1)
		check_flags(info, argv[1]);
	if (info->flags->h || (argc - info->flags->exists) != 2)
		put_manual(info);
	ft_memset(info->champion_name, '\0', PROG_NAME_LENGTH + 1);
	ft_memset(info->champion_comment, '\0', COMMENT_LENGTH + 1);
	info->prog_size = 0;
	info->new_fd = 0;
	info->magic = COREWAR_EXEC_MAGIC;
	info->file_name = argv[info->flags->exists + 1];
	info->line = NULL;
	info->command = NULL;
	info->num_line = 0;
	return (info);
}
