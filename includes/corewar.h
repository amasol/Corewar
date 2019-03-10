/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:32:46 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:32:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "SDL.h"
# include "SDL_mixer.h"
# include <ncurses.h>
# include <fcntl.h>
# include "op_corewar.h"

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int v;
	int	m;
	int	n;
	int	dump;
	int	dump_value;
	int	dump_bytes;
	int	lives;
	int	cycles;
	int	ops;
	int	deaths;
	int	moves;
}				t_flags;

typedef struct	s_bot
{
	int				id;
	unsigned int	prog_size;
	unsigned int	lives_current_period;
	unsigned int	cycle_last_live;
	unsigned char	*exec_code;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
}				t_bot;

typedef struct	s_map
{
	unsigned char	cell;
	int				color;
	int				temp_color;
	int				cycles;
}				t_map;

typedef struct	s_carriage
{
	int					id;
	int					carry;
	int					opcode;
	int					alive;
	int					arg_type[3];
	int					cycles_left;
	int					cycle_last_live;
	int					number_of_arguments;
	int					registers[REG_NUMBER + 1];
	t_bot				*parent;
	unsigned int		position;
	struct s_carriage	*next;
}				t_carriage;

/*
** s_vm - структура, в которой хранятся все структуру и переменные необходимые
** для работы виртуальной машины.
** w - окно, где отображается карта при визуализации;
** info - окно, где отображается информация при визуализации;
** flags - структура, где хранятся флаги, которые полученны при компиляции;
** bots - статичекая структура, где записанна вся информация про ботов;
** last_live_bot - указатель на бота, над которым последний раз выполняли
** операцию live
** map - структура, где хранится наша карта;
** carriage - список всех кареток;
** music_init - флаг, который определяет включенна музыка или нет;
** x - координата по оси x, используется при визуализации;
** y - координата по оси y, используется при визуализации;
** argc - количество полученных аргументов;
** fd - файловый дескриптор файла, из которого проводилось чтение бота;
** delay - задержка, используется для изменения скорости визуализации;
** cycles_in_second - количество циклов в секунду при визуализации;
** current_cycle - текущий цикл выполнения команд;
** running - флаг, который определяет визуализация идет или на паузе;
** number_of_bots - количесвто полученных ботов;
** num_of_carriages - количество созданных кареток;
** current_num_of_carriages - текущее количесвто живых кареток;
** cycle_check - цикл, на котором будет произведенна следующая проверка;
** cycle_to_die - параметр, который меняет цикл проверки кареток;
** number_of_lives - количество выполнений операций live за текущий период;
** number_of_checks - число проведенных подряд проверок;
** available_id - массив свободных id, нужен для флага -n
** argv - полученные аргументы;
** error_reason - причина ошибки.
*/

typedef struct	s_vm
{
	WINDOW			*w;
	WINDOW			*info;
	Mix_Music		*music;
	t_flags			*flags;
	t_bot			bot[4];
	t_bot			*last_live_bot;
	t_map			map[MEM_SIZE];
	t_carriage		*carriage;
	float			current_lives[4];
	float			previous_lives[4];
	int				music_init;
	int				x;
	int				y;
	int				argc;
	int				fd;
	int				delay;
	int				cycles_in_second;
	int				current_cycle;
	int				running;
	int				number_of_bots;
	int				num_of_carriages;
	int				current_num_of_carriages;
	int				cycle_check;
	int				cycle_to_die;
	int				number_of_lives;
	int				number_of_checks;
	int				available_id[5];
	char			**argv;
	char			*error_reason;
}				t_vm;

typedef struct	s_operations
{
	char	*name;
	int		opcode;
	int		number_args;
	int		type_args[3];
	int		dir_size;
	int		code_type;
	int		cycles;
	void	(*function)(t_vm *, t_carriage *);
}				t_operations;

t_vm			*init_info(int argc, char **argv);
void			put_manual(t_vm *info);
void			error(t_vm *info);
void			error_reason(t_vm *info, char *reason);
void			print_winner(t_vm *vm);

void			parse_arguments(t_vm *info);
int				is_natural(char *s);
void			check_bot(t_vm *info, int *i);
unsigned int	reverse(unsigned int value, int size);

void			define_bots_id(t_vm *info);
void			fill_map(t_vm *info);

void			visualization_init(t_vm *vm);
void			close_visulization(t_vm *vm);
int				check_key(int ch, t_vm *vm);
void			draw_map(t_vm *vm);
void			draw_period(t_vm *vm);
void			draw_info_table(t_vm *vm);
void			sdl_mixer_init(t_vm *vm);
void			npause(t_vm *vm);
void			draw_phrase(t_vm *vm);
void			winner(t_vm *vm);

void			introducing_contestants(t_vm *vm);
void			print_map(t_vm *vm);

void			new_carriage(t_vm *info, t_bot *parent, int position);
void			perform_carriages(t_vm *vm);
void			move_carriage(t_vm *vm, t_carriage *carriage);
void			check_carriages(t_vm *vm);
void			copy_carriage_data(t_carriage *dst, t_carriage *src);

int				check_code_type(t_vm *vm, t_carriage *carriage);
int				check_registers(t_vm *vm, t_carriage *carriage);
int				get_size_by_type(t_carriage *carriage, int i);
unsigned int	get_arg_from_map(t_map *map, unsigned int pos, int size);
int				get_arg_by_type(t_vm *vm, t_carriage *carriage, int index);
int				get_arg_position(t_carriage *carriage, int index);
void			rewrite_map(t_vm *vm, t_carriage *carr, int value, int addr);

void			ft_live(t_vm *vm, t_carriage *carriage);
void			ft_zjmp(t_vm *vm, t_carriage *carriage);
void			ft_and(t_vm *vm, t_carriage *carriage);
void			ft_add(t_vm *vm, t_carriage *carriage);
void			ft_sub(t_vm *vm, t_carriage *carriage);
void			ft_ld(t_vm *vm, t_carriage *carriage);
void			ft_or(t_vm *vm, t_carriage *carriage);
void			ft_xor(t_vm *vm, t_carriage *carriage);
void			ft_st(t_vm *vm, t_carriage *carriage);
void			ft_ldi(t_vm *vm, t_carriage *carriage);
void			ft_sti(t_vm *vm, t_carriage *carriage);
void			ft_fork(t_vm *vm, t_carriage *carriage);
void			ft_lfork(t_vm *vm, t_carriage *carriage);
void			ft_lld(t_vm *vm, t_carriage *carriage);
void			ft_lldi(t_vm *vm, t_carriage *carriage);
void			ft_aff(t_vm *vm, t_carriage *carriage);

#endif
