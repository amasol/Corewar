/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:47:52 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:47:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	assembler(t_asm *info)
{
	check_name_and_comment(info);
	check_commands_and_labels(info);
	check_end_of_file(info);
	operations_coding(info);
	analyze_labels(info);
	create_file(info);
	print_bytecode(info);
}

static void	disassembler(t_asm *info)
{
	ft_printf("disassembler for %s\n", info->file_name);
	check_binary_file(info);
	read_champion_code(info);
	create_file(info);
	print_champion_file(info);
}

int			main(int argc, char **argv)
{
	t_asm	*info;

	info = init_info(argc, argv);
	check_file_name(info);
	(info->flags->d) ? disassembler(info) : assembler(info);
	bonuses(info);
	return (0);
}
