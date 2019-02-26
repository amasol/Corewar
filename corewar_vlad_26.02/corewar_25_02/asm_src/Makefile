# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/11/09 11:37:55 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror
ASM_SRC = main.c bonuses.c init_info.c put_manual.c check_name_and_comment.c \
	error.c check_file_name.c get_name_and_comment.c check_end_of_file.c \
	check_commands_and_labels.c is_contains_label.c find_opcode.c \
	new_command.c add_labels.c parse_command.c array_len.c character_count.c \
	trim_arguments.c get_type.c analyze_arguments.c operations_coding.c \
	analyze_labels.c print_bytecode.c reverse.c check_binary_file.c \
	read_champion_code.c get_arg_by_type.c create_file.c \
	print_champion_file.c
ASM_OBJ = $(ASM_SRC:.c=.o)
ASM_HEADER = ../includes/asm.h ../includes/op.h
HEADER = -I ../includes
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(NAME)

$(NAME) : $(LIB) $(ASM_OBJ) 
	@echo "Compiling asm"
	@gcc $(FLAGS) $(ASM_OBJ) -o $(NAME) $(LIB)

$(ASM_OBJ): $(ASM_SRC) $(ASM_HEADER)
	@echo "Asm objects creating"
	@gcc $(FLAGS) -c $(ASM_SRC) $(HEADER)

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(ASM_OBJ)

n :
	@norminette $(ASM_SRC) 

fclean:
	@$(DEL) $(ASM_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all
