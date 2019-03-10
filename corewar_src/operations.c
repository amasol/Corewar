/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:33:35 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/28 10:33:37 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Сделанные команды (+) :
** live (+)
** ld (+)
** st (+)
** add (+)
** sub (+)
** and (+)
** or (+)
** xor (+)
** zjmp (+)
** ldi (+)
** sti (+)
** fork (+)
** lld (+)
** lldi (+)
** lfork (+)
** aff (+)
*/

const t_operations g_operations[16] = {
	{
		.name = "live",
		.opcode = 1,
		.number_args = 1,
		.type_args = {T_DIR, 0, 0},
		.dir_size = 4,
		.code_type = 0,
		.cycles = 10,
		.function = &ft_live
	},
	{
		.name = "ld",
		.opcode = 2,
		.number_args = 2,
		.type_args = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 5,
		.function = &ft_ld
	},
	{
		.name = "st",
		.opcode = 3,
		.number_args = 2,
		.type_args = {T_REG, T_IND | T_REG, 0},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 5,
		.function = &ft_st
	},
	{
		.name = "add",
		.opcode = 4,
		.number_args = 3,
		.type_args = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 10,
		.function = &ft_add
	},
	{
		.name = "sub",
		.opcode = 5,
		.number_args = 3,
		.type_args = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 10,
		.function = &ft_sub
	},
	{
		.name = "and",
		.opcode = 6,
		.number_args = 3,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 6,
		.function = &ft_and
	},
	{
		.name = "or",
		.opcode = 7,
		.number_args = 3,
		.type_args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 6,
		.function = &ft_or
	},
	{
		.name = "xor",
		.opcode = 8,
		.number_args = 3,
		.type_args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 6,
		.function = &ft_xor
	},
	{
		.name = "zjmp",
		.opcode = 9,
		.number_args = 1,
		.type_args = {T_DIR, 0, 0},
		.dir_size = 2,
		.code_type = 0,
		.cycles = 20,
		.function = &ft_zjmp
	},
	{
		.name = "ldi",
		.opcode = 10,
		.number_args = 3,
		.type_args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.dir_size = 2,
		.code_type = 1,
		.cycles = 25,
		.function = &ft_ldi
	},
	{
		.name = "sti",
		.opcode = 11,
		.number_args = 3,
		.type_args = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.dir_size = 2,
		.code_type = 1,
		.cycles = 25,
		.function = &ft_sti
	},
	{
		.name = "fork",
		.opcode = 12,
		.number_args = 1,
		.type_args = {T_DIR, 0, 0},
		.dir_size = 2,
		.code_type = 0,
		.cycles = 800,
		.function = &ft_fork
	},
	{
		.name = "lld",
		.opcode = 13,
		.number_args = 2,
		.type_args = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 10,
		.function = &ft_lld
	},
	{
		.name = "lldi",
		.opcode = 14,
		.number_args = 3,
		.type_args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.dir_size = 2,
		.code_type = 1,
		.cycles = 50,
		.function = &ft_lldi
	},
	{
		.name = "lfork",
		.opcode = 15,
		.number_args = 1,
		.type_args = {T_DIR, 0, 0},
		.dir_size = 2,
		.code_type = 0,
		.cycles = 1000,
		.function = &ft_lfork
	},
	{
		.name = "aff",
		.opcode = 16,
		.number_args = 1,
		.type_args = {T_REG, 0, 0},
		.dir_size = 4,
		.code_type = 1,
		.cycles = 2,
		.function = &ft_aff
	}
};
