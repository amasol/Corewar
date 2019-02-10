.PHONY: all clean fclean

NAME = corewar
CC=clang
#CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft
LIBFT = libft/libft.a

SRC = main.c error.c bot_size.c save_bot.c function_check.c ft_add.c\
      op.c \
#      ft_sti.c  ft_and.c  ft_aff.c ft_fork.c ft_ld.c ft_ldi.c \
#     ft_lfork.c ft_live.c ft_lld.c ft_lldi.c ft_or.c ft_st.c ft_sub.c ft_xor.c \
#      ft_zjmp.c
OBJ = $(SRC:.c=.o)

OBJDIR=obj
SRCDIR=src

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ)) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@ -lncurses
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
