/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:59:27 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/07 17:59:39 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H

# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define SECOND_COMMENT_CHAR	';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct	s_operations
{
	char	*name;
	int		opcode;
	int		number_args;
	int		type_args[3];
	int		dir_size;
	int		code_type;
}				t_operations;

static t_operations g_operations[17] = {
	{"live", 1, 1, {T_DIR, 0, 0}, 4, 0},
	{"ld", 2, 2, {T_DIR | T_IND, T_REG, 0}, 4, 1},
	{"st", 3, 2, {T_REG, T_IND | T_REG, 0}, 4, 1},
	{"add", 4, 3, {T_REG, T_REG, T_REG}, 4, 1},
	{"sub", 5, 3, {T_REG, T_REG, T_REG}, 4, 1},
	{"and", 6, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"or", 7, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"xor", 8, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1},
	{"zjmp", 9, 1, {T_DIR, 0, 0}, 2, 0},
	{"ldi", 10, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1},
	{"sti", 11, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 2, 1},
	{"fork", 12, 1, {T_DIR, 0, 0}, 2, 0},
	{"lld", 13, 2, {T_DIR | T_IND, T_REG, 0}, 4, 1},
	{"lldi", 14, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1},
	{"lfork", 15, 1, {T_DIR, 0, 0}, 2, 0},
	{"aff", 16, 1, {T_REG, 0, 0}, 4, 1},
	{NULL, 0, 0, {0, 0, 0}, 0, 0}
};

#endif
