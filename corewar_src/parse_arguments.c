/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:19:56 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/13 14:19:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_cycles_value(t_vm *info, int *i, int bytes)
{
	(*i)++;
	if (*i >= info->argc || !is_natural(info->argv[*i]))
	{
		info->error_reason = "Wrong number of cycles after the flag -dump";
		put_manual(info);
	}
	info->flags->dump = 1;
	info->flags->dump_value = ft_atoi(info->argv[*i]);
	info->flags->dump_bytes = bytes;
	(*i)++;
}

static void	get_detalization_level(t_vm *vm, int *i)
{
	int	detail;

	(*i)++;
	if (*i >= vm->argc || !is_natural(vm->argv[*i]))
		vm->error_reason = "Wrong level of detalization after the flag -s";
	else if (ft_atoi(vm->argv[*i]) > 31)
		vm->error_reason = "Level of detalization after the flag -s > 31";
	if (vm->error_reason)
		put_manual(vm);
	detail = ft_atoi(vm->argv[*i]);
	vm->flags->lives = ((detail | 1) == detail) ? 1 : vm->flags->lives;
	vm->flags->cycles = ((detail | 2) == detail) ? 1 : vm->flags->cycles;
	vm->flags->ops = ((detail | 4) == detail) ? 1 : vm->flags->ops;
	vm->flags->deaths = ((detail | 8) == detail) ? 1 : vm->flags->deaths;
	vm->flags->moves = ((detail | 16) == detail) ? 1 : vm->flags->moves;
	(*i)++;
}

static void	get_bot_id(t_vm *info, int *i)
{
	int	id;

	(*i)++;
	id = 0;
	if (*i >= info->argc || !is_natural(info->argv[*i]))
		info->error_reason = "Wrong id of a bot after the flag -n";
	if (*i + 1 >= info->argc)
		info->error_reason = "No champ.cor after the flag -n N";
	else
	{
		id = ft_atoi(info->argv[*i]);
		if (id < 1 || id > 4)
			info->error_reason = "Id of a bot must be 1-4";
		else if (info->available_id[id] == 1)
			info->error_reason = "Id of a bot can't repeat";
	}
	if (info->error_reason)
		put_manual(info);
	info->available_id[id] = 1;
	(*i)++;
	check_bot(info, i);
	info->bot[info->number_of_bots - 1].id = id;
	info->flags->n = 1;
}

static void	get_flags(t_vm *info, int *num)
{
	int		i;
	char	*s;

	s = info->argv[*num];
	i = 1;
	while (s[i])
	{
		if (!ft_strchr("hlcvm", (int)s[i]))
			check_bot(info, num);
		i++;
	}
	i = 1;
	while (s[i])
	{
		info->flags->h = (s[i] == 'h') ? 1 : info->flags->h;
		info->flags->l = (s[i] == 'l') ? 1 : info->flags->l;
		info->flags->c = (s[i] == 'c') ? 1 : info->flags->c;
		info->flags->v = (s[i] == 'v') ? 1 : info->flags->v;
		info->flags->m = (s[i] == 'm') ? 1 : info->flags->m;
		i++;
	}
	if (info->flags->h)
		put_manual(info);
	(*num)++;
}

void		parse_arguments(t_vm *info)
{
	char	*arg;
	int		i;

	i = 1;
	while (i < info->argc)
	{
		arg = info->argv[i];
		if (!ft_strcmp(arg, "-dump") || !ft_strcmp(arg, "-dump64"))
			get_cycles_value(info, &i, 64);
		else if (!ft_strcmp(arg, "-dump32"))
			get_cycles_value(info, &i, 32);
		else if (!ft_strcmp(info->argv[i], "-s"))
			get_detalization_level(info, &i);
		else if (!ft_strcmp(info->argv[i], "-n"))
			get_bot_id(info, &i);
		else if (info->argv[i][0] == '-' && info->argv[i][1])
			get_flags(info, &i);
		else
			check_bot(info, &i);
	}
	if (!info->number_of_bots)
	{
		info->error_reason = "No champion indicated";
		put_manual(info);
	}
}
