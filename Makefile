# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 19:09:46 by amasol            #+#    #+#              #
#    Updated: 2018/10/26 21:46:42 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHONY: all clean fclean

NAME = corewar
CC=clang
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft
LIBFT = libft/libft.a

SRC = main.c
OBJ = $(SRC:.c=.o)

OBJDIR=obj
SRCDIR=src

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ)) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo ""
	@echo "-----------------------------------"
	@echo "Corewar is ready to work"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@printf "."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C libft

clean:
	@echo "-----------------------------------"
	@echo "Objects files are removed"
	@ /bin/rm -rf $(OBJDIR)
	@$(MAKE) --no-print-directory -C libft clean

fclean:
	@echo "-----------------------------------"
	@echo "Corewar is deleted"
	@ /bin/rm -rf $(OBJDIR)
	@ /bin/rm -f $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean

re: fclean all
