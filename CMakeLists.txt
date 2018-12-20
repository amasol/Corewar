cmake_minimum_required(VERSION 3.12)
project(corewar C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(corewar
        ${LIBA}
        include/corewar.h
        libft/libft.h
        include/op.h
        src/main.c
        src/error.c
        src/shift_bit.c
        src/save_bot.c
        src/function_check.c
        src/op.c
        src/ft_sti.c
        src/ft_and.c
        src/ft_add.c
        src/ft_aff.c
        src/ft_fork.c
        src/ft_ld.c
        src/ft_ld.c
        src/ft_ldi.c
        src/ft_lfork.c
        src/ft_live.c
        src/ft_lld.c
        src/ft_lldi.c
        src/ft_or.c
        src/ft_st.c
        src/ft_sub.c
        src/ft_xor.c
        src/ft_zjmp.c)

link_libraries(libft/libftprintf.a)